from splashkit import *

values = ["123", "45.67", "hello", "abc", "-789", "0"]

write_line("Let's check if these values are numbers:")

for value in values:
    # Check if the string is a valid number
    is_number_value = is_number(value)

    # Print the value along with the result using a clearer message
    if is_number_value:
        write_line(f"'{value}' is a valid number: true")
    else:
        write_line(f"'{value}' is not a valid number: false")
