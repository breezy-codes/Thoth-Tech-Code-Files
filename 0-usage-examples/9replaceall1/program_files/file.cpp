#include "splashkit.h"

int main()
{
    string sentence = "I like apple pie. Apple is great.";

    // Replace all occurrences of "apple" with "orange"
    string modified = replace_all(sentence, "apple", "orange");

    write_line("Modified sentence: " + modified);

    return 0;
}