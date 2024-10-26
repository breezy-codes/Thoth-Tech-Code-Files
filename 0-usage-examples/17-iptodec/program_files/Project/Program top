using static SplashKitSDK.SplashKit;
using System.Text.RegularExpressions;

// Function to validate if the input is a valid IPv4 address
bool IsValidIPv4(string ip)
{
    string ipPattern = @"^(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\."
                     + @"(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\."
                     + @"(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\."
                     + @"(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])$";
    return Regex.IsMatch(ip, ipPattern);
}

WriteLine("Convert IP addresses from IPv4 to decimal format.");

bool exitRequested = false;

while (!exitRequested)
{
    // Prompt the user for an IP input in dotted decimal format
    WriteLine("\nPlease enter an IPv4 address in dotted decimal format (e.g., 127.0.0.1), or type 'exit' to quit:");

    // Read the input as a string
    string ipInput = ReadLine();

    // Exit the loop if the user types 'exit'
    if (ipInput == "exit")
    {
        WriteLine("Goodbye!");
        exitRequested = true;
    }
    else
    {
        // Validate IP format
        if (!IsValidIPv4(ipInput))
        {
            WriteLine("Invalid IPv4 address format. Please try again.");
        }
        else
        {
            // Convert the IPv4 string to decimal
            uint ipAsDec = Ipv4ToDec(ipInput);

            // Display the results
            WriteLine("The IP address in decimal format is: " + ipAsDec);
        }
    }
}
