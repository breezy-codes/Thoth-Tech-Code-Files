from splashkit import *

# Lets read into this string...
name = "unknown"

# Open a window to show the user...
open_window("Reading Input.", 800, 600)

# Load a font for text rendering
load_font("input", "arial.ttf")

# Define area where text should appear
rect = rectangle_from(230.0, 50.0, 200.0, 30.0)

# Start reading text in this area
# This could be in the loop, if we had a button or something to click to trigger this
start_reading_text(rect)

# Here is our game loop

while not quit_requested():

    # Listen for input... thiss will update the text read
    process_events()

    # Click anywhere on the screen to trigger the text input
    if (mouse_clicked(MouseButton.left_button)):

        # Start reading text in the rectagle area
        start_reading_text(rect)


    # Looks like we finished reading text...
    if not reading_text():
        # Was input cancelled
        if text_entry_cancelled():
            name = "unknown"
        else:
            # Get the name from the text input
            name = text_input()

    # Draw the screen...
    clear_screen(color_white())

    draw_rectangle_record(color_black(), rect)

    # If we are reading text... then show what it is
    if reading_text():
        draw_collected_text(color_black(), font_named("input"), 18, option_defaults())

    # Draw text instructions
    draw_text("Click anywhere to start reading text", color_red(), font_named("input"), 18, 200, 100)

    # Draw what we have in the name
    draw_text(name, color_black(), font_named("input"), 18, 10, 10)

    # Show it...
    refresh_screen_with_target_fps(60)

close_all_windows()