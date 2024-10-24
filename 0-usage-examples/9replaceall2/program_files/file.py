from splashkit import *

write_line("Please enter a sentence:")
sentence = read_line()

write_line("Please enter the word to replace:")
old_word = read_line()

write_line("Please enter the new word:")
new_word = read_line()

# Replace all occurrences of the old word with the new word
modified = replace_all(sentence, old_word, new_word)

write_line(f"Modified sentence: {modified}")
