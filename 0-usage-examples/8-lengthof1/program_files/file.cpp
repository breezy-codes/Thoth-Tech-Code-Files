#include "splashkit.h"

int main()
{
    string text = "SplashKit";

    // Get the length of the string
    int length = length_of(text);

    write_line("The length of the string is: " + std::to_string(length));

    return 0;
}
