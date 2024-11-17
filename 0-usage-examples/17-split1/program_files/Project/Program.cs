using SplashKitSDK;
using System.Text.RegularExpressions;

namespace Program
{
    public class Program
    {
        public static void Main()
        {
            // Function to validate if the input is a valid IPv4 address
            bool IsValidIPv4(string ip)
            {
                string ipPattern = @"^(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\."
                                + @"(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\."
                                + @"(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\."
                                + @"(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])$";
                return Regex.IsMatch(ip, ipPattern);
            }

            SplashKit.WriteLine("Convert IP addresses from IPv4 to decimal format.");

            bool exitRequested = false;

            while (!exitRequested)
            {
                // Prompt the user for an IP input in dotted decimal format
                SplashKit.WriteLine("\nPlease enter an IPv4 address in dotted decimal format (e.g., 127.0.0.1), or type 'exit' to quit:");

                // Read the input as a string
                string ipInput = SplashKit.ReadLine();

                // Exit the loop if the user types 'exit'
                if (ipInput == "exit")
                {
                    SplashKit.WriteLine("Goodbye!");
                    exitRequested = true;
                }
                else
                {
                    // Validate IP format
                    if (!IsValidIPv4(ipInput))
                    {
                        SplashKit.WriteLine("Invalid IPv4 address format. Please try again.");
                    }
                    else
                    {
                        // Convert the IPv4 string to decimal
                        uint ipAsDec = SplashKit.Ipv4ToDec(ipInput);

                        // Display the results
                        SplashKit.WriteLine("The IP address in decimal format is: " + ipAsDec);
                    }
                }
            }
        }
    }
}