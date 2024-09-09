from splashkit import *

SCREEN_BORDER = 100

def update_camera_position(player_x, player_y):

    # Test edge of screen boundaries to adjust the camera
    left_edge = camera_x() + SCREEN_BORDER
    right_edge = left_edge + screen_width() - 2 * SCREEN_BORDER
    top_edge = camera_y() + SCREEN_BORDER
    bottom_edge = top_edge + screen_height() - 2 * SCREEN_BORDER

    # Test if the player is outside the area and move the camera
    # the player will appear to stay still and everything else
    # will appear to move :)

    # Test top/bottom of screen
    if player_y < top_edge:
        move_camera_by(0, player_y - top_edge)
    elif player_y > bottom_edge:
        move_camera_by(0, player_y - bottom_edge)

    # Test left/right of screen
    if player_x < left_edge:
        move_camera_by(player_x - left_edge, 0)
    elif player_x > right_edge:
        move_camera_by(player_x - right_edge, 0)

# Start of "main" code
open_window("Camera Test", 800, 800)

player_x, player_y = 400, 400

while not quit_requested():
    # Handle input to adjust player movement
    process_events()

    if key_down(KeyCode.left_key): player_x -= 3
    if key_down(KeyCode.right_key): player_x += 3
    if key_down(KeyCode.down_key): player_y += 3
    if key_down(KeyCode.up_key): player_y -= 3

    update_camera_position(player_x, player_y)

    # Redraw everything
    clear_screen(color_black())

    # Draw to the screen
    fill_rectangle(color_dim_gray(), 0, 0, screen_width(), 50)
    draw_text_no_font_no_size_with_options("HUD", color_white(), 10, 10, option_to_screen())
    draw_text_no_font_no_size_with_options(f"Camera Position: {point_to_string(camera_position())}", color_white(), 10, 30, option_to_screen())

    # as well as the player who can move
    fill_circle(color_yellow(), player_x, player_y, 20)

    # including something stationary - it doesn't move
    fill_rectangle(color_white(), 400, 200, 10, 10)

    refresh_screen_with_target_fps(60)

close_all_windows()