#include "splashkit.h"

int main()
{
    write_line("Get ready! A random float between 0 and 1 is about to drop...");
    write_line("Here it comes...");

    // Generate a random float between 0 and 1
    float random_float = rnd();

    write_line("Boom! Your random float is: " + std::to_string(random_float));
    write_line("What a surprise! Let's see what happens next!");

    return 0;
}