import sys, os, shutil
import json
import xml.etree.ElementTree as ET
import subprocess
import zipfile
import re
from PIL import Image, ImageDraw, ImageFilter

GLOBALS_PATH = "globals.xml"
SCREENS_PATH = "screens"
CONVERT_SCRIPT = "LVGLImage.py"

TEST_XML = '''<test>
	<view extends="__FOLDER__" />
	<steps>
		<screenshot_compare path="screens/__FOLDER__/screen.png" />
	</steps>
</test>
'''

def change_globals_font(input_path = GLOBALS_PATH, output_path = GLOBALS_PATH, new_value="true"):
    """
    Update <bin> elements in an XML file.
    - Sets as_file=<new_value> if src_path does NOT contain '/core'
    - Preserves comments and formatting
    """
    # Read original text
    with open(input_path, "r", encoding="utf-8") as f:
        xml_text = f.read()

    # Parse XML for structure
    tree = ET.ElementTree(ET.fromstring(xml_text))
    root = tree.getroot()

    # Collect bins to modify
    changes = {}
    for bin_elem in root.findall(".//fonts/bin"):
        src_path = bin_elem.get("src_path", "")
        name = bin_elem.get("name")
        if "/core" not in src_path and name:
            changes[name] = new_value

    # Regex function to replace or add as_file attribute
    def update_as_file(match):
        full_tag = match.group(0)
        name = match.group(1)
        if name in changes:
            if 'as_file=' in full_tag:
                # Replace existing as_file
                full_tag = re.sub(r'as_file="[^"]*"', f'as_file="{changes[name]}"', full_tag)
            else:
                # Add attribute before closing tag
                full_tag = full_tag[:-1] + f' as_file="{changes[name]}">'
        return full_tag

    # Apply regex replacement
    xml_text = re.sub(
        r'<bin[^>]*name="([^"]+)"[^>]*>',
        update_as_file,
        xml_text
    )

    # Write modified XML
    with open(output_path, "w", encoding="utf-8") as f:
        f.write(xml_text)
    
def create_zip(zip_name, file_paths):
    with zipfile.ZipFile(zip_name, 'w', zipfile.ZIP_DEFLATED) as zipf:
        for file_path in file_paths:
            # Add file with its relative name (no full path)
            arcname = os.path.basename(file_path)
            zipf.write(file_path, arcname)
    print(f"Created {zip_name} with {len(file_paths)} files.")

def load_globals():
    """Parse globals.xml and return dict of global images excluding images/core/"""
    tree = ET.parse(GLOBALS_PATH)
    root = tree.getroot()

    images = {}
    for data in root.findall(".//images/data"):
        name = data.get("name")
        src_path = data.get("src_path")
        if not src_path.startswith("images/core/"):
            images[name] = src_path
    fonts = {}
    for data in root.findall(".//fonts/bin"):
        name = data.get("name")
        src_path = data.get("src_path")
        if not src_path.startswith("fonts/core/"):
            fonts[name] = src_path

    return images, fonts

# def process_preview(src_path):
#     img = Image.open(src_path).convert("RGBA")
#     img = img.resize((205, 251))

#     # Create a rounded mask
#     radius = 50  # adjust for more or less rounding
#     mask = Image.new("L", img.size, 0)
#     draw = ImageDraw.Draw(mask)
#     draw.rounded_rectangle([(0, 0), img.size], radius=radius, fill=255)

#     # Apply the mask as alpha channel
#     img.putalpha(mask)
#     img.save(src_path, format="PNG")


def process_preview(src_path, dest_path, glow_color=(255, 255, 255, 255), glow_radius=10, corner_radius=45):
    final_size = (205, 251)

    # 1. Load and shrink the original image to make room for glow
    img = Image.open(src_path).convert("RGBA")
    shrink = glow_radius  # shrink margin on each side
    inner_size = (final_size[0] - 2 * shrink, final_size[1] - 2 * shrink)
    img = img.resize(inner_size)

    # 2. Create rounded mask for the shrunken image
    mask = Image.new("L", inner_size, 0)
    draw = ImageDraw.Draw(mask)
    draw.rounded_rectangle([(0, 0), inner_size], radius=corner_radius, fill=255)
    img.putalpha(mask)

    # 3. Create full-size canvas and glow layer
    canvas = Image.new("RGBA", final_size, (0, 0, 0, 0))

    # Glow mask same shape but placed in center
    glow_mask = Image.new("L", final_size, 0)
    draw = ImageDraw.Draw(glow_mask)
    draw.rounded_rectangle(
        [(shrink, shrink), (final_size[0] - shrink, final_size[1] - shrink)],
        radius=corner_radius,
        fill=255
    )

    # Blur for glow softness
    blurred = glow_mask.filter(ImageFilter.GaussianBlur(glow_radius / 2))
    glow = Image.new("RGBA", final_size, glow_color)
    glow.putalpha(blurred)

    # 4. Composite glow and centered image
    result = Image.alpha_composite(canvas, glow)
    result.paste(img, (shrink, shrink), img)

    # 5. Save final image (same size as original)
    result.save(dest_path, format="PNG")

def convert_image(src_path, dest_path, preview = False):
    """Run external conversion script to generate .bin file."""
    os.makedirs(os.path.dirname(dest_path), exist_ok=True)

    out_folder = dest_path.split('/')
    out_folder = '/'.join(out_folder[:-1])
    try:
        if preview:
            subprocess.run(
                ["python3", CONVERT_SCRIPT, "--ofmt", "BIN", "--cf", "I8", "-o", out_folder, "--name", "preview", src_path],
                check=True
            )
        else:
            subprocess.run(
                ["python3", CONVERT_SCRIPT, "--ofmt", "BIN", "--cf", "I8", "-o", out_folder, src_path],
                check=True
            )
        print(f"⚙️  Converted {src_path} → {dest_path}")
    except subprocess.CalledProcessError as e:
        print(f"❌ Error converting {src_path}: {e}")
    except FileNotFoundError:
        print(f"❌ Missing {CONVERT_SCRIPT} or Python executable!")


def process_folder(dirpath, global_images, global_fonts, run_test = False):
    """Process one folder: detect image usage, update info.json, convert assets."""
    xml_files = [f for f in os.listdir(dirpath) if f.endswith(".xml")]
    if not xml_files:
        return None

    folder_rel_path = os.path.relpath(dirpath, SCREENS_PATH)
    matched_images = set()
    matched_fonts = set()

    print(f"Processing {folder_rel_path}")
    # Generate test file and run it

    if run_test: 
        # basically generate the preview screenshot
        with open("test.xml", "w") as wf:
            wf.write(f"{TEST_XML.replace("__FOLDER__", folder_rel_path)}")

        subprocess.run(
            ["./lved-cli.js", "run-test", "./", "./test.xml"],
            check=True
        )
    
    info_path = os.path.join(dirpath, "info.json")

    zip_files = []
    zip_files.append(info_path)
    info_data = {}
    readme_json = {}
    readme_json["preview"] = ""

    if os.path.exists(info_path):
        try:
            with open(info_path, "r", encoding="utf-8") as f:
                info_data = json.load(f)
        except json.JSONDecodeError:
            pass  # reset if invalid

    if "name" not in info_data:
        info_data["name"] = folder_rel_path.title()
    if "desc" not in info_data:
        info_data["desc"] = f"{folder_rel_path}"

    info_data["main"] = f"{xml_files[0]}"
    main_file = os.path.join(dirpath, f"{xml_files[0]}")
    if f"main.xml" in xml_files:
        info_data["main"] = f"main.xml"
        main_file = os.path.join(dirpath, f"main.xml")

    if f"{folder_rel_path}.xml" in xml_files:
        info_data["main"] = f"{folder_rel_path}.xml"
        main_file = os.path.join(dirpath, f"{folder_rel_path}.xml")
    
    zip_files.append(main_file)
    # Check XMLs for image usage
    for xml_file in xml_files:
        xml_path = os.path.join(dirpath, xml_file)
        with open(xml_path, "r", encoding="utf-8") as f:
            content = f.read()
            for name, src_path in global_images.items():
                if f'="{name}"' in content:
                    matched_images.add(name)
            for name, src_path in global_fonts.items():
                if f'="{name}"' in content:
                    matched_fonts.add(name)

    info_data["fonts"] = []
    info_data["images"] = []

    if matched_images:

        # Add images to JSON
        image_entries = [f"{name}.bin" for name in sorted(matched_images)]
        info_data["images"] = image_entries

        # Convert each matched image to .bin
        for name in matched_images:
            src_path = global_images[name]
            dest_bin = os.path.join(dirpath, f"{name}.bin")
            convert_image(src_path, dest_bin)
            zip_files.append(dest_bin)

    if matched_fonts:
        # Add fonts to JSON
        image_entries = [f"{name}" for name in sorted(matched_fonts)]
        info_data["fonts"] = image_entries
        for name in matched_fonts:
            src_path = f"fonts/{name}"
            dest_path = os.path.join(dirpath, f"{name}")
            print(f"{src_path} {dest_path}")
            shutil.copyfile(src_path, dest_path)
            zip_files.append(dest_path)

    screen_png = os.path.join(dirpath, "screen.png")
    preview_png = os.path.join(dirpath, "preview.png")
    if os.path.exists(screen_png):
        process_preview(screen_png, preview_png)

    # Convert preview.png if exists
    if os.path.exists(preview_png):
        readme_json["preview"] = f"{folder_rel_path}/preview.png"
        preview_bin = os.path.join(dirpath, "preview.bin")
        convert_image(preview_png, preview_bin, True)
        info_data["preview"] = f"preview.bin"
        zip_files.append(preview_bin)
    
    with open(info_path, "w", encoding="utf-8") as f:
        json.dump(info_data, f, indent=4)
    print(f"✅ Updated {info_path}")

    readme_json["name"] = info_data["name"]
    readme_json["desc"] = info_data["desc"]

    dest_zip = os.path.join(dirpath, f"{folder_rel_path}.zip")

    create_zip(dest_zip, zip_files)

    readme_json["download"] = f"https://github.com/fbiego/s3_watchfaces/raw/refs/heads/master/screens/{folder_rel_path}/{folder_rel_path}.zip"

    return readme_json
    

def scan_screens(global_images, global_fonts, run_test = False):
    """Recursively walk /screens/ and process each subfolder."""
    """Create the README.md file with the watchfaces"""
    readme = """## Watchfaces

| Preview               |  Name               |
| --------------------- | --------------------|
"""
    for dirpath, _, _ in os.walk(SCREENS_PATH):
        face = process_folder(dirpath, global_images, global_fonts, run_test)
        if face:
            readme += f'| ![{face["name"]}]({face["preview"]}?raw=true "{face["name"]}") | [**{face["name"]}**]({face["download"]}) |\n'
   
    with open("screens/README.md", "w") as rd:
        rd.write(readme)


def generate_compile_project():
    try:
        print(f"⚙️  Generating project")
        subprocess.run(
            ["./lved-cli.js", "generate", "./"],
            check=True
        )
        print(f"⚙️  Compiling project")
        subprocess.run(
            ["./lved-cli.js", "compile", "./", "--target", "node"],
            check=True
        )
    except subprocess.CalledProcessError as e:
        print(f"❌ Error compiling: {e}")
    except FileNotFoundError:
        print(f"❌ Missing lved-cli.js")

def create_faces(run_cli = False):
    change_globals_font(new_value="true")

    if run_cli:
        generate_compile_project()

    global_images, global_fonts = load_globals()
    print(f"Loaded {len(global_images)} global images and {len(global_fonts)} global fonts")
    scan_screens(global_images, global_fonts, run_test=run_cli) # currently not working

    change_globals_font(new_value="false")


if __name__ == "__main__":

    cli = len(sys.argv) >= 2
    # cli need lved-cli.js & lvgl-resources.zip on the root folder
    # download from https://pro.lvgl.io/#download Command Line Interface according to your platform
    create_faces(cli)