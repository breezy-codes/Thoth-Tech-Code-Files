#include "splashkit.h"

int main()
{
    string input = "5.5";
    write_line("String input: " + input);
    
    // Convert input string to double
    double number = convert_to_double(input);

    // Calculate the square of the number
    double square = number * number;

    write_line("The square of the number is: " + std::to_string(square));

    return 0;
}
