#include "splashkit.h"

int main()
{
    write_line("Countdown with Decimals:");
    for (double i = 5.0; i >= 0.0; i -= 0.5)
    {
        write("T-minus ");
        write(i);
        write_line(" seconds!");
    }
    write_line("Blast off!");
    return 0;
}
