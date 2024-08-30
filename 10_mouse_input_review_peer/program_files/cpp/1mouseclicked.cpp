#include "splashkit.h"

int main()
{
    open_window("Mouse Inputs", 800, 600);

    while (!window_close_requested("Mouse Inputs"))
    {
        // process user input events
        process_events();

        // change screen colour to red if left mouse button is clicked
        if (mouse_clicked(LEFT_BUTTON))
        {
            clear_screen(COLOR_RED);
        }
        // change screen colour to yellow if right mouse button is clicked
        else if (mouse_clicked(RIGHT_BUTTON))
        {
            clear_screen(COLOR_YELLOW);
        }

        refresh_screen(60);
    }

    close_all_windows();

    return 0;
}