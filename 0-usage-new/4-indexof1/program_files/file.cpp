#include "splashkit.h"

int main()
{
    string sentence = "The cat is on the roof.";
    string word = "cat";
    write_line("Sentence: " + sentence);
    write_line("Word: " + word);

    // Find index of the word "cat"
    int index = index_of(sentence, word);

    write_line("The index of the word 'cat' is: " + std::to_string(index));

    return 0;
}
