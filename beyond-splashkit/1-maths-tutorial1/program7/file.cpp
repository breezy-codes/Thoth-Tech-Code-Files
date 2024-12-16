#include "splashkit.h"

const int MAX_DEGREE = 100;  // Define a maximum degree for polynomials

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

// Read a polynomial from the user
void read_polynomial(int poly[], int& degree)
{
    degree = read_valid_integer("Enter the degree of the polynomial: ");

    for (int i = degree; i >= 0; i--)
    {
        poly[i] = read_valid_integer("Enter coefficient for x^" + std::to_string(i) + ": ");
    }

    // Initialise unused coefficients (those beyond the entered degree) to 0
    for (int i = degree + 1; i <= MAX_DEGREE; i++)
    {
        poly[i] = 0;
    }
}

// Print a polynomial to the console
void print_polynomial(const int poly[], int degree)
{
    for (int i = degree; i >= 0; i--)
    {
        if (poly[i] != 0)
        {
            if (i != degree && poly[i] > 0)
                write("+");
            if (i == 0 || poly[i] != 1)
                write(std::to_string(poly[i]));
            if (i > 0)
                write("x");
            if (i > 1)
                write("^" + std::to_string(i));
            write(" ");
        }
    }
}

// Add two polynomials together
void add_polynomials(const int a[], int a_degree, const int b[], int b_degree, int result[], int& result_degree)
{
    result_degree = std::max(a_degree, b_degree);

    for (int i = 0; i <= result_degree; i++)
    {
        int coef_a = (i <= a_degree) ? a[i] : 0;
        int coef_b = (i <= b_degree) ? b[i] : 0;
        result[i] = coef_a + coef_b;
    }

    // Initialise any unused coefficients in result array to 0
    for (int i = result_degree + 1; i <= MAX_DEGREE; i++)
    {
        result[i] = 0;
    }
}

// Multiply two polynomials together
void multiply_polynomials(const int a[], int a_degree, const int b[], int b_degree, int result[], int& result_degree)
{
    result_degree = a_degree + b_degree;

    // Initialise result array to 0
    for (int i = 0; i <= result_degree; i++)
    {
        result[i] = 0;
    }

    for (int i = 0; i <= a_degree; i++)
    {
        for (int j = 0; j <= b_degree; j++)
        {
            result[i + j] += a[i] * b[j];
        }
    }

    // Initialise any unused coefficients in result array to 0
    for (int i = result_degree + 1; i <= MAX_DEGREE; i++)
    {
        result[i] = 0;
    }
}

int main()
{
    int poly1[MAX_DEGREE + 1] = {0};  // Array for first polynomial
    int poly2[MAX_DEGREE + 1] = {0};  // Array for second polynomial
    int result[MAX_DEGREE * 2 + 1] = {0};  // Result array (max possible degree = MAX_DEGREE * 2)
    int degree1 = 0, degree2 = 0, result_degree = 0;

    write_line("Enter the first polynomial:");
    read_polynomial(poly1, degree1);

    write_line("Enter the second polynomial:");
    read_polynomial(poly2, degree2);

    write("Enter operation (+ or *): ");
    string input_op = read_line();
    char operation = input_op[0];

    // Print the polynomials to show what is being added or multiplied
    write("First polynomial: ");
    print_polynomial(poly1, degree1);

    write("Second polynomial: ");
    print_polynomial(poly2, degree2);

    if (operation == '+')
    {
        add_polynomials(poly1, degree1, poly2, degree2, result, result_degree);
        write_line("Result of addition:");
    }
    else if (operation == '*')
    {
        multiply_polynomials(poly1, degree1, poly2, degree2, result, result_degree);
        write_line("Result of multiplication:");
    }
    else
    {
        write_line("Invalid operation.");
        return 0;
    }

    // Print the result polynomial
    print_polynomial(result, result_degree);

    return 0;
}
