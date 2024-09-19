from splashkit import *

# Read user input
write("Enter first number: ")
snum_1 = read_line()
write("Enter second number: ")
snum_2 = read_line()


# Convert user inputs to integers
inum_1 = convert_to_integer(snum_1)
inum_2 = convert_to_integer(snum_2)

# Compute the result
result = inum_1 * inum_2

# Output the result
write(snum_1 + " multiplied by " + snum_2 + " equals ")
write_line_int(result)