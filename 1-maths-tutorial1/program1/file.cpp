#include "splashkit.h"

// Calculate the square root of a number
double sqrt(int n)
{
    if (n == 0 || n == 1)
        return n;

    double estimate = n;
    double precision = 0.00001;

    while ((estimate - n / estimate) > precision)
    {
        estimate = (estimate + n / estimate) / 2.0;
    }

    return estimate;
}

// Check if a number is prime
bool is_prime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

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

int main()
{
    int number = read_valid_integer("Enter an integer: ");

    if (is_prime(number))
    {
        write_line(std::to_string(number) + " is a prime number.");
    }
    else
    {
        write_line(std::to_string(number) + " is not a prime number.");
    }

    return 0;
}
