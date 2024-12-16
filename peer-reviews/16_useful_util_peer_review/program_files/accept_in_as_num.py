from splashkit import *

def read_integer(prompt):
    # Prompt the user with the message
    write(prompt)

    # Read the user input as a string.
    line = read_line()

    # Loop while the user's input is NOT a valid whole number.
    while not is_integer(line):

        # If the user input was not a valid whole number, ask them to enter a whole number.
        write_line("Please enter a valid whole number.")
        write(prompt)
        line = read_line()

    # Convert the user input to an integer before returning it.
    return convert_to_integer(line)

# Start of "main" code
height = read_integer("Enter your height in centimetres: ")

write("You are ")
write_int(height)
write_line("cm tall!")