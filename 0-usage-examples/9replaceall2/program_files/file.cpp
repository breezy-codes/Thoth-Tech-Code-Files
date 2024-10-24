#include "splashkit.h"

int main()
{
    write_line("Please enter a sentence:");
    string sentence = read_line();

    write_line("Please enter the word to replace:");
    string old_word = read_line();

    write_line("Please enter the new word:");
    string new_word = read_line();

    // Replace all occurrences of the old word with the new word
    string modified = replace_all(sentence, old_word, new_word);

    write_line("Modified sentence: " + modified);

    return 0;
}
