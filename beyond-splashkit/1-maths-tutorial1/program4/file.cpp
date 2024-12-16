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

int main()
{
    // Get the limit up to which we want to find primes
    int limit = read_valid_integer("Find all prime numbers up to: ");

    // Find all primes up to the limit
    write_line("Prime numbers up to " + std::to_string(limit) + ":");
    for (int i = 2; i <= limit; i++)
    {
        if (is_prime(i))
        {
            write(std::to_string(i) + " ");
        }
    }
    write_line(""); // print out all the prime numbers

    return 0;
}
