from splashkit import *

write_line("Please enter a value:")
input_value = read_line()

# Check if the input is a valid integer
value = is_integer(input_value)

if value:
    write_line("The input is a valid integer.")
else:
    write_line("The input is not a valid integer.")
