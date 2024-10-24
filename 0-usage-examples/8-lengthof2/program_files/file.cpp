#include "splashkit.h"

int main()
{
    write_line("Please enter a string:");
    string input = read_line();

    // Get the length of the input string
    int length = length_of(input);

    write_line("The length of the input string is: " + std::to_string(length));

    return 0;
}
