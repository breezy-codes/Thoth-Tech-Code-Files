﻿using SplashKitSDK;

namespace CheckTerminalInput
{
    public class Program
    {
        public static void Main()
        {
            SplashKit.WriteLine("Welcome to the Terminal Input Checker!");
            SplashKit.WriteLine("Type something and press Enter to see it echoed back.");
            SplashKit.WriteLine("Type 'exit' and press Enter to quit the program.");

            string input;

            do
            {
                // Wait for input if available
                if (SplashKit.TerminalHasInput())
                {
                    input = SplashKit.ReadLine();
                    if (input != "exit")
                    {
                        SplashKit.WriteLine("You typed: " + input);
                    }
                }
                else
                {
                    input = string.Empty; // If no input, continue waiting
                }
            } while (input != "exit");

            SplashKit.WriteLine("Exiting the program...");
        }
    }
}
