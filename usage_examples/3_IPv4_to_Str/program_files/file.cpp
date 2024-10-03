#include "splashkit.h"
using std::to_string;

int main()
{
    string ip_input;
    write_line("The IP address 127.0.0.1 converts to 2130706433 as an integer.");
    write_line("Enter an integer to be converted to an IPv4 address (or type 'quit' to exit):");
    write_line("=========================================================");
    while (true)
    {
        write("Enter the Ipv4 to convert: ");
        ip_input = read_line();
        if (ip_input == "quit")
        {break;}
        int ip_as_int = convert_to_integer(ip_input);
        string ip_str = ipv4_to_str(ip_as_int);
        write_line("You entered: " + ip_input);
        write_line("Converted the Integer to IPv4 String: " + ip_str);
        write_line("=========================================================");
    }
    write_line("Goodbye!");
    return 0;
}
