from splashkit import *

sentence = "The robot loves apple juice. Apple is its favourite fruit."

# Display the original sentence
write_line(f"Original sentence: {sentence}")

# Replace all occurrences of "apple" with "bolts"
modified = replace_all(sentence, "apple", "bolts")

# Display the modified sentence
write_line(f"Modified sentence: {modified}")
