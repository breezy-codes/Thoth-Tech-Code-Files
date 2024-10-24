#include "splashkit.h"

int main()
{
    write_line("Please enter a string:");
    string input = read_line();

    // Convert input to lowercase
    string upper = to_lowercase(input);

    write_line("Lowercase: " + upper);

    return 0;
}
