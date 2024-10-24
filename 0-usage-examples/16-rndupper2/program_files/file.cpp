#include "splashkit.h"

int main()
{
    write_line("Please enter an upper bound:");
    int upper_bound = convert_to_integer(read_line());

    // Generate a random number within the limit
    int random_number = rnd(upper_bound);

    write_line("Random number: " + std::to_string(random_number));

    return 0;
}