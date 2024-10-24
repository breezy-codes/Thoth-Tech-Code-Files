#include "splashkit.h"

int main()
{
    write_line("Please enter the lower bound:");
    int lower = convert_to_integer(read_line());

    write_line("Please enter the upper bound:");
    int upper = convert_to_integer(read_line());

    // Generate a random number within the given range
    int random_number = rnd(lower, upper);

    write_line("Random number: " + std::to_string(random_number));

    return 0;
}
