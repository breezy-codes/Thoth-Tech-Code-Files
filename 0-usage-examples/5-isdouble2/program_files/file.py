from splashkit import *

write_line("Please enter a value:")
input_value = read_line()

# Check if the input is a valid double
value = is_double(input_value)

if value:
    write_line("The input is a valid double.")
else:
    write_line("The input is not a valid double.")
