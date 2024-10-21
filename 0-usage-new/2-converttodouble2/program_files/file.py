from splashkit import *

write_line("Please enter a number:")
input_value = read_line()

# Convert input string to double
number = convert_to_double(input_value)

# Calculate the square of the number
square = number * number

write_line(f"The square of the number is: {square}")