#include "splashkit.h"

int main()
{
    write_line("Please enter the delay time in milliseconds:");
    int delay_time = convert_to_integer(read_line());

    // Delay for the user-specified time
    delay(delay_time);

    write_line("Wait is over.");

    return 0;
}
