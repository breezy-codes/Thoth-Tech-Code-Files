#include "splashkit.h"

int main()
{
    // colour variables
    double hue = 0.8;
    double saturation = 0.8;
    double brightness = 0.8;

    // mouse movement variable
    vector_2d movement;

    open_window("Mouse Movement", 800, 600);

    while (!window_close_requested("Mouse Movement"))
    {
        // process user input events
        process_events();

        // store the mouse movement direction and distance to the movement variable
        movement = mouse_movement();

        // change screen colour 'hue' if left mouse button is held down
        if (mouse_down(LEFT_BUTTON))
        {
            // change hue of screen colour based on horizontal mouse movement
            hue += movement.x / screen_width();
        }
        // change screen colour 'saturation' if right mouse button is held down
        if (mouse_down(RIGHT_BUTTON))
        {
            // change saturation of screen colour based on vertical mouse movement
            saturation += movement.y / screen_height();
        }

        // display current screen colour
        clear_screen(hsb_color(hue, saturation, brightness));
        refresh_screen(60);
    }

    close_all_windows();

    return 0;
}