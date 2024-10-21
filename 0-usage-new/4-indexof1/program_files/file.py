from splashkit import *

sentence = "The cat is on the roof."
word = "cat"
write_line("Sentence: " + sentence)
write_line("Word: " + word)

# Find index of the word "cat"
index = index_of(sentence, word)

write_line(f"The index of the word 'cat' is: {index}")