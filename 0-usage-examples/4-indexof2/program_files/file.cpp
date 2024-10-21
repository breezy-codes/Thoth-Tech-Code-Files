#include "splashkit.h"

int main()
{
    write_line("Please enter a sentence:");
    string sentence = read_line();

    write_line("Please enter the word to find:");
    string word = read_line();

    // Find index of the word in the sentence
    int index = index_of(sentence, word);

    write_line("The index of the the word is: " + std::to_string(index));

    return 0;
}