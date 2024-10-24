#include "splashkit.h"

int main()
{
    write_line("Get ready to generate a random number between 1 and 100...");
    write_line("Drum roll please...");

    // Generate a random number between 1 and 100
    int random_number = rnd(1, 100);

    write_line("🎲 Your lucky number is: " + std::to_string(random_number) + " 🎲");
    write_line("Feeling lucky? Maybe it's time to play the lottery!");

    return 0;
}
