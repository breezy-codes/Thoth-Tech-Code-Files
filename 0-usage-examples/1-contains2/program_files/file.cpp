#include "splashkit.h"

int main()
{
    write_line("Please enter a sentence:");
    string sentence = read_line();

    // Check if the sentence contains "SplashKit"
    if (contains(sentence, "SplashKit"))
    {
        write_line("Your sentence contains the word 'SplashKit'.");
    }
    else
    {
        write_line("Your sentence does not contain 'SplashKit'.");
    }

    return 0;
}
