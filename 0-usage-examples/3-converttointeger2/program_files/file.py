from splashkit import *

write_line("Please enter a number:")
input_value = read_line()

# Convert input string to integer
number = convert_to_integer(input_value)

# Check if the number is odd or even
if number % 2 == 0:
    write_line("The number is even.")
else:
    write_line("The number is odd.")
