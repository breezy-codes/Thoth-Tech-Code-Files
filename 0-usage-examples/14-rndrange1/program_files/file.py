from splashkit import *

write_line("Let's make this more interesting!")

# Get user input for the range
write_line("Please enter the minimum number:")
min_value = int(read_line())

write_line("Please enter the maximum number:")
max_value = int(read_line())

# Validate if min is smaller than max
if min_value >= max_value:
    write_line("Oops! The minimum value should be less than the maximum value.")
else:
    write_line(f"Get ready to generate a random number between {min_value} and {max_value}...")
    write_line("Drum roll please...")

    # Generate a random number in the specified range
    random_number = rnd(min_value, max_value)

    write_line(f"🎲 Your lucky number is: {random_number} 🎲")
    write_line("How does it feel? Want to try again?")
