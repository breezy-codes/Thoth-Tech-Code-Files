from splashkit import *
import re

# Function to validate if the input is a valid IPv4 address
def is_valid_ipv4(ip):
    ip_pattern = re.compile(r"^(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\."
                            r"(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\."
                            r"(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\."
                            r"(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])$")
    return bool(ip_pattern.match(ip))

write_line("Convert IP addresses from IPv4 to hexadecimal format.")

exit_requested = False

while not exit_requested:
    # Prompt the user for an IP input in dotted decimal format
    write_line("\nPlease enter an IPv4 address in dotted decimal format (e.g., 127.0.0.1), or type 'exit' to quit:")

    # Read the input as a string
    ip_input = read_line()

    # Exit the loop if the user types 'exit'
    if ip_input == "exit":
        write_line("Goodbye!")
        exit_requested = True
    else:
        # Validate IP format
        if not is_valid_ipv4(ip_input):
            write_line("Invalid IPv4 address format. Please try again.")
        else:
            # Convert the IPv4 string to hexadecimal
            ip_as_hex = ipv4_to_hex(ip_input)

            # Display the results
            write_line("The IP address in hexadecimal format is: " + ip_as_hex)
