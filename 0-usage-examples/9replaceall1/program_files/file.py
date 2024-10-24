from splashkit import *

sentence = "I like apple pie. Apple is great."

# Replace all occurrences of "apple" with "orange"
modified = replace_all(sentence, "apple", "orange")

write_line(f"Modified sentence: {modified}")
