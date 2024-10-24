using SplashKitSDK;

namespace CalculatePrimeNumber
{
    public class Program
    {
        public static void Main()
        {
            // Calculate the square root of a number
            double Sqrt(int n)
            {
                if (n == 0 || n == 1)
                    return n;

                double estimate = n;
                double precision = 0.00001;

                while ((estimate - n / estimate) > precision)
                {
                    estimate = (estimate + n / estimate) / 2.0;
                }

                return estimate;
            }

            // Check if a number is prime
            bool IsPrime(int n)
            {
                if (n <= 1) return false;
                for (int i = 2; i <= Sqrt(n); i++)
                {
                    if (n % i == 0)
                        return false;
                }
                return true;
            }

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

            // Main logic
            int number = ReadValidInteger("Enter an integer: ");

            if (IsPrime(number))
            {
                SplashKit.WriteLine(number + " is a prime number.");
            }
            else
            {
                SplashKit.WriteLine(number + " is not a prime number.");
            }

        }
    }
}