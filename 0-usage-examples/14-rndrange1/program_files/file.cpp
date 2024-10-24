#include "splashkit.h"

int main()
{
    // Generate a random number between 1 and 100
    int random_number = rnd(1, 100);

    write_line("Random number between 1 and 100: " + std::to_string(random_number));

    return 0;
}
