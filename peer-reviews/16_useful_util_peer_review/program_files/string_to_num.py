from splashkit import *

## Convert the string "2017" to an integer 2017
some_string = "2017"
some_number = convert_to_integer(some_string)

write("The value of some_number is: ")
write_line_int(some_number)

## Convert the string "3.14159265358979" to a double ~3.141593
pi_string = "3.14159265358979"
pi = convert_to_double(pi_string)

write("The value of pi is: ")
write_line_double(pi)