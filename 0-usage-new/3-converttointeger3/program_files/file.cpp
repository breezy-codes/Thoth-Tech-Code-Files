#include "splashkit.h"

int main()
{
    write_line("Please enter a number:");
    string input = read_line();

    // Convert string to integer
    int result = convert_to_integer(input);

    write_line("The value as an integer is: " + std::to_string(result));

    return 0;
}
