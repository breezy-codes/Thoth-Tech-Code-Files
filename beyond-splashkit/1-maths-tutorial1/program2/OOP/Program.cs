using SplashKitSDK;

namespace GCDCalculator
{
    public class Program
    {
        public static void Main()
        {
            // Ensure the user enters a valid integer
            int ReadValidInteger(string prompt)
            {
                int number;
                SplashKit.Write(prompt);
                string input = SplashKit.ReadLine();

                while (!SplashKit.IsInteger(input))
                {
                    SplashKit.WriteLine("Invalid integer input. Please enter a valid integer.");
                    SplashKit.Write(prompt);
                    input = SplashKit.ReadLine();
                }

                number = SplashKit.ConvertToInteger(input);
                return number;
            }

            // Calculate the greatest common divisor of two numbers
            int Gcd(int a, int b)
            {
                while (b != 0)
                {
                    int temp = b;
                    b = a % b;
                    a = temp;
                }
                return a;
            }

            // Main logic
            int num1 = ReadValidInteger("Enter the first integer: ");
            int num2 = ReadValidInteger("Enter the second integer: ");

            // Calculate the GCD of the two numbers
            int result = Gcd(num1, num2);
            SplashKit.WriteLine("The GCD of " + num1 + " and " + num2 + " is " + result);
        }
    }
}