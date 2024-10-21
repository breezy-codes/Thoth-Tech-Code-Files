#include "splashkit.h"

int main()
{
    string value = "42.8";
    write_line("String value: " + value);

    // Convert string to integer
    int result = convert_to_integer(value);

    write_line("The value as an integer is: " + std::to_string(result));

    return 0;
}
