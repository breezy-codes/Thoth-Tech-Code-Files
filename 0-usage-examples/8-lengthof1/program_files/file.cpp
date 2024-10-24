#include "splashkit.h"

int main()
{
    string text = "SplashKit";

    write_line("Processing the string: '" + text + "'");

    // Get the length of the string
    int length = length_of(text);

    write_line("The length of the string is: " + std::to_string(length) + " characters.");

    return 0;
}
