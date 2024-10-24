#include "splashkit.h"

int main()
{
    // Get the ticks before delay
    unsigned int ticks_before = current_ticks();
    write_line("Ticks before: " + std::to_string(ticks_before));

    // Delay for 10 seconds (10000 milliseconds)
    delay(10000);

    // Get the ticks after delay
    unsigned int ticks_after = current_ticks();
    write_line("Ticks after: " + std::to_string(ticks_after));

    return 0;
}