#include "splashkit.h"

int main()
{
    open_window("Mouse Location", 800, 600);

    while (!window_close_requested("Mouse Location"))
    {
        // process user input events
        process_events();

        // draw blue circle at mouse position
        clear_screen(COLOR_WHITE);
        fill_circle(COLOR_LIGHT_BLUE, circle_at(mouse_position(), 20));
        refresh_screen(60);
    }

    close_all_windows();

    return 0;
}