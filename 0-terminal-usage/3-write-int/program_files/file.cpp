#include "splashkit.h"

int main()
{
    write_line("Countdown (Integer Version):");
    for (int i = 10; i >= 0; i--)
    {
        write("T-minus ");
        write(i); // Writing an integer
        write_line(" seconds...");
    }
    write_line("Lift off!");
    return 0;
}
