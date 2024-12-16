#include "splashkit.h"

int main()
{
    string sentence = "The robot loves apple juice. Apple is its favourite fruit.";
    
    // Display the original sentence
    write_line("Original sentence: " + sentence);

    // Replace all occurrences of "apple" with "bolts"
    string modified = replace_all(sentence, "apple", "bolts");

    // Display the modified sentence
    write_line("Modified sentence: " + modified);

    return 0;
}
