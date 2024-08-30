from splashkit import *

def main():

    hue = 0.8
    saturation = 0.8
    brightness = 0.8


    window = open_window("Mouse Movement", 800, 600)

    while not window_close_requested(window):

        process_events()

        # Get the mouse movement
        movement = mouse_movement()

        # Update hue and saturation based on mouse movement
        if mouse_down(MouseButton.left_button):
            # Adjust hue based on horizontal mouse movement
            hue = (hue + movement.x / window_width(window)) % 1.0

        if mouse_down(MouseButton.right_button):
            # Adjust saturation based on vertical mouse movement
            saturation = min(max(saturation + movement.y / window_height(window), 0.0), 1.0)

        # Create the color using HSB values
        color = hsb_color(hue, saturation, brightness)

        # Clear the screen with the new color
        clear_screen(color)


        refresh_window(window)


    close_window(window)

if __name__ == "__main__":
    main()