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

// Ensure a valid operation is entered
char read_valid_operation()
{
    char operation;
    string input;

    do
    {
        write("Enter an operation (+, -, *, ^): ");
        input = read_line();
        operation = input[0];

        if (operation != '+' && operation != '-' && operation != '*' && operation != '^')
        {
            write_line("Invalid operation. Please enter a valid operation (+, -, *, ^).");
        }
    } while (operation != '+' && operation != '-' && operation != '*' && operation != '^');

    return operation;
}

// Calculate the modular exponentiation of a number
int modular_exponentiation(int base, int exponent, int mod)
{
    int result = 1;
    base = base % mod;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % mod;

        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main()
{
    // Collect the modulus, numbers, and operation from the user
    int mod = read_valid_integer("Enter the modulus: ");
    int a = read_valid_integer("Enter the first number: ");
    
    // Validate and read the operation
    char operation = read_valid_operation();

    int b = read_valid_integer("Enter the second number: ");

    int result;

    switch (operation)
    {
        case '+':
            result = (a + b) % mod;
            break;
        case '-':
            result = (a - b + mod) % mod;
            break;
        case '*':
            result = (a * b) % mod;
            break;
        case '^':
            result = modular_exponentiation(a, b, mod);
            break;
        default:
            return;
    }

    write_line("Result: " + std::to_string(result));

    return 0;
}
