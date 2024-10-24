#include "splashkit.h"

// Calculate the square root of a double number
double sqrt(double n)
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

// Ensure the user enters a valid double
double read_valid_double(const string &prompt)
{
    double number;
    write(prompt);
    string input = read_line();

    while (!is_double(input))
    {
        write_line("Invalid input. Please enter a valid number.");
        write(prompt);
        input = read_line();
    }

    number = convert_to_double(input);
    return number;
}

int main()
{
    // Input coefficients with validation
    double a = read_valid_double("Enter coefficient a: ");
    double b = read_valid_double("Enter coefficient b: ");
    double c = read_valid_double("Enter coefficient c: ");

    // Calculate the discriminant of the quadratic equation
    double discriminant = b * b - 4 * a * c;

    // Check if 'a' is zero, which would not be a quadratic equation
    if (a == 0)
    {
        write_line("Coefficient a cannot be zero.");
    }
    else if (discriminant > 0)
    {
        // Two real roots
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        write_line("Real roots:");
        write_line("x1 = " + std::to_string(x1));
        write_line("x2 = " + std::to_string(x2));
    }
    else if (discriminant == 0)
    {
        // One real root
        double x = -b / (2 * a);
        write_line("One real root:");
        write_line("x = " + std::to_string(x));
    }
    else
    {
        // Complex roots
        double real_part = -b / (2 * a);
        double imaginary_part = sqrt(-discriminant) / (2 * a);
        write_line("Complex roots:");
        write_line("x1 = " + std::to_string(real_part) + " + " + std::to_string(imaginary_part) + "i");
        write_line("x2 = " + std::to_string(real_part) + " - " + std::to_string(imaginary_part) + "i");
    }

    return 0;
}
