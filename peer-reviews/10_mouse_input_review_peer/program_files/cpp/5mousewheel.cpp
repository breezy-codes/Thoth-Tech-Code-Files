#include "splashkit.h"

int main()
{
    // color variables
    double hue = 0.6;
    double saturation = 0.6;
    double brightness = 0.6;

    // mouse scroll variable
    vector_2d scroll;

    open_window("Mouse Scrolling", 800, 600);

    while (!window_close_requested("Mouse Scrolling"))
    {
        // process user input events
        process_events();

        // store the mouse wheel scroll direction and distance to the scroll variable
        scroll = mouse_wheel_scroll();

        // change hue of screen colour based on vertical mouse scrolling (two fingers if using trackpad)
        hue += scroll.y / 100;

        // display current screen colour
        clear_screen(hsb_color(hue, saturation, brightness));
        refresh_screen(60);
    }

    close_all_windows();

    return 0;
}