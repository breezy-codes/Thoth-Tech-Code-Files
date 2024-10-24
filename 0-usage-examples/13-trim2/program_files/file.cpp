#include "splashkit.h"

int main()
{
    write_line("Please enter a string with spaces:");
    string input = read_line();

    // Trim leading/trailing spaces
    string trimmed = trim(input);

    write_line("Trimmed string: '" + trimmed + "'");

    return 0;
}
