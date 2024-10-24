from splashkit import *

write_line("Please enter a string:")
input_value = read_line()

# Convert input to lowercase
upper = to_lowercase(input_value)

write_line(f"Lowercase: {upper}")
