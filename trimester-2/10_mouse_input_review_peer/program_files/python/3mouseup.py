from splashkit import *


COLOR_RED = color_red()
COLOR_WHITE = color_white()

def main():

    window = open_window("Mouse Inputs", 800, 600)

    while not window_close_requested(window):
        # Process user input events
        process_events()

        # Change screen color to red if the left mouse button is not pressed
        if not mouse_down(MouseButton.left_button):
            clear_screen(COLOR_RED)
        # Change screen color to white if the left button is pressed
        else:
            clear_screen(COLOR_WHITE)


        refresh_window(window)


    close_window(window)

if __name__ == "__main__":
    main()