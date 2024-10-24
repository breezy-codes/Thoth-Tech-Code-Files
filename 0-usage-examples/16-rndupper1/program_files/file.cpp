#include "splashkit.h"

int main()
{
    // Generate a random number between 0 and 50
    int random_number = rnd(50);

    write_line("Random number between 0 and 50: " + std::to_string(random_number));

    return 0;
}