#include "splashkit.h"

int main()
{
    // Simulate a coin toss using a random float
    float random_float = rnd();

    if (random_float < 0.5)
    {
        write_line("Heads");
    }
    else
    {
        write_line("Tails");
    }

    return 0;
}