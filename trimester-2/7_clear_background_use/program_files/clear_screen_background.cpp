#include "splashkit.h"

int main()
{
    open_window("Back Ground", 800, 600);

    // suggested code changes have been commented out for now:
    //clear_screen(COLOR_WHITE);
    //refresh_screen(60);
    //delay(5000);
    clear_screen(COLOR_BLUE);
    refresh_screen(60);
    delay(5000);

    close_all_windows();

    return 0;
}