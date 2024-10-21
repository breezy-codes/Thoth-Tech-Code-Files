#include "splashkit.h"

int main()
{
    // User input will initially be stored in these two strings.
    string snum_1, snum_2;

    // And then it will be converted and stored in these integers.
    int inum_1, inum_2, result;

    // Read user input
    write("Enter first number: ");
    snum_1 = read_line();
    write("Enter second number: ");
    snum_2 = read_line();

    // Convert user input to integers
    inum_1 = convert_to_integer(snum_1);
    inum_2 = convert_to_integer(snum_2);

    // Compute the result
    result = inum_1 * inum_2;

    // Output the results
    write(snum_1 + " multiplied by " + snum_2 + " equals ");
    write_line(result);

    return 0;
}