#include "splashkit.h"

int main()
{
    write_line("Please enter a number:");
    string input = read_line();

    // Convert input string to integer
    int number = convert_to_integer(input);

    // Check if the number is odd or even
    if (number % 2 == 0)
    {
        write_line("The number is even.");
    }
    else
    {
        write_line("The number is odd.");
    }

    return 0;
}