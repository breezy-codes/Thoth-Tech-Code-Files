from splashkit import *

write_line("Please enter a sentence:")
sentence = read_line()

write_line("Please enter the word to find:")
word = read_line()

# Find index of the word in the sentence
index = index_of(sentence, word)

write_line(f"The index of the word is: {index}")