#include "splashkit.h"

int main()
{
    write_line("Please enter a number to convert to a double:");
    string value = read_line();
    
    // Convert string to double
    double result = convert_to_double(value);

    write_line("The value as a double is: " + std::to_string(result));

    return 0;
}