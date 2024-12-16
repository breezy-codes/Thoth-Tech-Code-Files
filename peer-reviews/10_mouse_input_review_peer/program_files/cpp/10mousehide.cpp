#include "splashkit.h"

int main()
{
    // create cirle variable for "black hole"
    circle blackHole;

    open_window("Mouse Visibility", 800, 600);

    // create black hole in centre of screen
    blackHole = circle_at(screen_center(), 50);

    while (!window_close_requested("Mouse Visibility"))
    {
        // process user input events
        process_events();

        // mouse disappears in black hole
        if (point_in_circle(mouse_position(), blackHole))
        {
            hide_mouse();
        }
        // mouse reappears once out of black hole
        else
        {
            show_mouse();
        }

        // display "black hole" on screen
        clear_screen(COLOR_WHITE);
        fill_circle(COLOR_BLACK, blackHole);
        refresh_screen(60);
    }

    close_all_windows();

    return 0;
}