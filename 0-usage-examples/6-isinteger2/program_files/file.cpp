#include "splashkit.h"

int main()
{
    write_line("Please enter a value:");
    string input = read_line();

    // Check if the input is a valid integer
    bool integer = is_integer(input);

    if (integer)
    {
        write_line("The input is a valid integer.");
    }
    else
    {
        write_line("The input is not a valid integer.");
    }

    return 0;
}
