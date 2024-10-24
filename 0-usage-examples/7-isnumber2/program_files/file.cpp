#include "splashkit.h"

int main()
{
    write_line("Please enter a value:");
    string input = read_line();

    // Check if the input is a number
    bool integer = is_number(input);

    if (integer)
    {
        write_line("The input is a number.");
    }
    else
    {
        write_line("The input is not a number.");
    }

    return 0;
}
