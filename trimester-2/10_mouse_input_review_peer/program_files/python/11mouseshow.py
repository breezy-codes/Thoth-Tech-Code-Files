from splashkit import *

def main():

    spotlight_radius = 100
    window_width, window_height = 800, 600
    window = open_window("Mouse Visibility in Spotlight", window_width, window_height)

    spotlight_center = point_at(window_width / 2, window_height / 2)

    mouse_visible = True

    while not window_close_requested(window):
        # Process user input events
        process_events()

        # Get the current mouse position
        mouse_pos = mouse_position()

        # Calculate distance from the mouse to the spotlight center
        dx = mouse_pos.x - spotlight_center.x
        dy = mouse_pos.y - spotlight_center.y
        distance = (dx ** 2 + dy ** 2) ** 0.5

        # Determine whether to show or hide the mouse
        if distance <= spotlight_radius:
            if not mouse_visible:
                show_mouse()  # Show the mouse
                mouse_visible = True
        else:
            if mouse_visible:
                hide_mouse()  # Hide the mouse
                mouse_visible = False

        # Clear the screen with black color
        clear_screen(color_black())

        # Draw the spotlight as a circle
        fill_circle(color_white(), spotlight_center.x, spotlight_center.y, spotlight_radius)

        refresh_window(window)

    close_all_windows()

if __name__ == "__main__":
    main()