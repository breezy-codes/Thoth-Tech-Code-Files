#include "splashkit.h"

int main()
{
    // create cirle variable for emulating a "stage spot light"
    circle spotLight;

    open_window("Mouse Visibility", 800, 600);

    // create a "spot light" circle in centre of screen
    spotLight = circle_at(screen_center(), 100);

    while (!window_close_requested("Mouse Visibility"))
    {
        // process user input events
        process_events();

        // mouse disappears when not in the "spot light"
        show_mouse(point_in_circle(mouse_position(), spotLight));

        // display "spot light" on screen
        clear_screen(COLOR_BLACK);
        fill_circle(COLOR_ALICE_BLUE, spotLight);
        refresh_screen(60);
    }

    close_all_windows();

    return 0;
}