#include "splashkit.h"

int main()
{
    // Convert the string "2017" to an integer 2017
    string some_string = "2017";
    int some_number = convert_to_integer(some_string);

    write("The value of some_number is: ");
    write_line(some_number);

    // Convert the string "3.14159265358979" to a double ~3.141593
    string pi_string = "3.14159265358979";
    double pi = convert_to_double(pi_string);

    write("The value of pi is: ");
    write_line(pi);

    return 0;
}