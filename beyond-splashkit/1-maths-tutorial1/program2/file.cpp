#include "splashkit.h"

// Ensure the user enters a valid integer
int read_valid_integer(const string &prompt)
{
    int number;
    write(prompt);
    string input = read_line();

    while (!is_integer(input))
    {
        write_line("Invalid integer input. Please enter a valid integer.");
        write(prompt);
        input = read_line();
    }

    number = convert_to_integer(input);
    return number;
}

// Calculate the greatest common divisor of two numbers
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    // Collect two valid integers from the user
    int num1 = read_valid_integer("Enter the first integer: ");
    int num2 = read_valid_integer("Enter the second integer: ");

    // Calculate the GCD of the two numbers
    int result = gcd(num1, num2);
    write_line("The GCD of " + std::to_string(num1) + " and " + std::to_string(num2) + " is " + std::to_string(result));

    return 0;
}