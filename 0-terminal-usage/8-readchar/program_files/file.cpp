#include "splashkit.h"

int main()
{
    write_line("Press a single character:");

    // Read a single character
    char user_char = read_char();

    // Output the character
    write_line("You pressed: " + string(1, user_char));

    return 0;
}
