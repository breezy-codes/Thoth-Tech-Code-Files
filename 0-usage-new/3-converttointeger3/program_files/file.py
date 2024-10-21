from splashkit import *

write_line("Please enter a number:")
input_value = read_line()

# Convert string to integer
result = convert_to_integer(input_value)

write_line(f"The value as an integer is: {result}")
