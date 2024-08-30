#include "splashkit.h"

int main()
{
    open_window("Mouse Inputs", 800, 600);

    while (!window_close_requested("Mouse Inputs"))
    {
        // process user input events
        process_events();

        // change screen colour to red if left mouse button is held down
        if (mouse_down(LEFT_BUTTON))
        {
            clear_screen(COLOR_RED);
        }
        // change screen colour to yellow if right mouse button is held down
        else if (mouse_down(RIGHT_BUTTON))
        {
            clear_screen(COLOR_YELLOW);
        }
        // change screen colour to white if no mouse button held down
        else
        {
            clear_screen(COLOR_WHITE);
        }
        refresh_screen(60);
    }

    close_all_windows();

    return 0;
}