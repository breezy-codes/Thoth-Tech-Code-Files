#include "splashkit.h"

int main()
{
    write_line("Please enter a value:");
    string input = read_line();

    // Check if the input is a valid double
    bool value = is_double(input);

    if (value)
    {
        write_line("The input is a valid double.");
    }
    else
    {
        write_line("The input is not a valid double.");
    }

    return 0;
}
