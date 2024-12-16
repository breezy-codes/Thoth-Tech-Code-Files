using SplashKitSDK;

namespace PrimeNumbers
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

            int limit = ReadValidInteger("Find all prime numbers up to: ");

            // Find all primes up to the limit
            SplashKit.WriteLine("Prime numbers up to " + limit + ":");
            for (int i = 2; i <= limit; i++)
            {
                if (IsPrime(i))
                {
                    SplashKit.Write(i + " ");
                }
            }
            SplashKit.WriteLine(""); // Print out all the prime numbers
        }
    }
}