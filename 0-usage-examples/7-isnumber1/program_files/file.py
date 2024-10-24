from splashkit import *

values = ["123", "45.67", "hello", "abc", "-789", "0"]

for value in values:
    # Check if string is a valid integer
    integer = is_number(value)

    # Print the value along with the result using "true" or "false"
    write_line(f"{value} - {'true' if integer else 'false'}")