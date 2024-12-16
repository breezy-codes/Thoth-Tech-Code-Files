#include "splashkit.h"
#include <regex>

// Function to validate if the input is a valid IPv4 address
bool is_valid_ipv4(const string &ip)
{
    const std::regex ip_pattern("^(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\\."
                                "(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\\."
                                "(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\\."
                                "(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])$");
    return std::regex_match(ip, ip_pattern);
}

int main()
{
    write_line("Convert IP addresses from IPv4 to decimal format.");

    bool exit_requested = false;

    while (!exit_requested)
    {
        // Prompt the user for an IP input in dotted decimal format
        write_line("\nPlease enter an IPv4 address in dotted decimal format (e.g., 127.0.0.1), or type 'exit' to quit:");
        
        // Read the input as a string
        string ip_input = read_line();

        // Exit the loop if the user types 'exit'
        if (ip_input == "exit")
        {
            write_line("Goodbye!");
            exit_requested = true;
        }
        else
        {
            // Validate IP format
            if (!is_valid_ipv4(ip_input))
            {
                write_line("Invalid IPv4 address format. Please try again.");
            }
            else
            {
                // Convert the IPv4 string to decimal
                unsigned int ip_as_dec = ipv4_to_dec(ip_input);

                // Display the results
                write_line("The IP address in decimal format is: " + std::to_string(ip_as_dec));
            }
        }
    }

    return 0;
}
