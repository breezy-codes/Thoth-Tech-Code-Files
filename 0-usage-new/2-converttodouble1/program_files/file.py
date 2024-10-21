from splashkit import *

write_line("Please enter a number to convert to a double:")
value = read_line()

# Convert string to double
result = convert_to_double(value)

write_line(f"The value as a double is: {result}")