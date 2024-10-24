from splashkit import *

write_line("Please enter a value:")
input_value = read_line()

# Check if the input is a number
value = is_number(input_value)

if value:
    write_line("The input is a number.")
else:
    write_line("The input is not a number.")
