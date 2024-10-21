#include "splashkit.h"

int main()
{
    float y = 0;

    open_window("Mouse Location", 800, 600);

    while (!window_close_requested("Mouse Location"))
    {
        // process user input events
        process_events();

        if (mouse_down(LEFT_BUTTON))
        {
            y = mouse_y();
        }

        clear_screen(COLOR_WHITE);
        fill_circle(COLOR_BLUE, 400, 300, 100);
        // draw purple "curtain" from top of screen to y coordinate of mouse
        fill_rectangle(COLOR_PURPLE, 0, 0, screen_width(), y);
        refresh_screen(60);
    }

    close_all_windows();

    return 0;
}