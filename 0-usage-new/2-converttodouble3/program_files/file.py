from splashkit import *

# Pre-specified number as a string
input_value = "5.5"
write_line("String: " + input_value)

# Convert input string to double
number = convert_to_double(input_value)

# Calculate the square of the number
square = number * number

write_line(f"The square of the number is: {square}")
