#include "splashkit.h"

int main()
{
    // Generate a random float between 0 and 1
    float random_float = rnd();

    write_line("Random float between 0 and 1: " + std::to_string(random_float));

    return 0;
}