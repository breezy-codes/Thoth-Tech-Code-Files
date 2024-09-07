#include "splashkit.h"

int main()
{
    // Greet the user
    write_line("Hello! Welcome to the IP to string converter.");

    // Prompt the user for an IP input in dotted decimal format (e.g., 192.168.1.2)
    write_line("Please enter an IPv4 address in integer format:");

    // Read the input as a string
    string ip_input = read_line();

    // Convert the input string to an integer using convert_to_integer
    int ip_as_int = convert_to_integer(ip_input);

    // Convert the integer back to the string format using ipv4_to_str
    string ip_str = ipv4_to_str(ip_as_int);

    // Display the result
    write_line("The IP address in string format is: " + ip_str);

    return 0;
}
