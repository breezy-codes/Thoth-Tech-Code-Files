#include "splashkit.h"

int main()
{
    open_window("Mouse Location", 800, 600);

    while (!window_close_requested("Mouse Location"))
    {
        // process user input events
        process_events();

        // draw line from mouse position vector
        clear_screen(COLOR_WHITE);
        draw_line(COLOR_BLUE, line_from(mouse_position_vector()));
        refresh_screen(60);
    }

    close_all_windows();

    return 0;
}