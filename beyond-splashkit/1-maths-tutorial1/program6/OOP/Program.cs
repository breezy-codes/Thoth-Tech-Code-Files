using SplashKitSDK;

namespace QuadraticEquationSolver
{
    public class Program
    {
        public static void Main()
        {
            // Calculate the square root of a double number
            double Sqrt(double n)
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

            // Ensure the user enters a valid double
            double ReadValidDouble(string prompt)
            {
                double number;
                SplashKit.Write(prompt);
                string input = SplashKit.ReadLine();

                while (!SplashKit.IsDouble(input))
                {
                    SplashKit.WriteLine("Invalid input. Please enter a valid number.");
                    SplashKit.Write(prompt);
                    input = SplashKit.ReadLine();
                }

                number = SplashKit.ConvertToDouble(input);
                return number;
            }

            // Main logic
            double a = ReadValidDouble("Enter coefficient a: ");
            double b = ReadValidDouble("Enter coefficient b: ");
            double c = ReadValidDouble("Enter coefficient c: ");

            // Calculate the discriminant of the quadratic equation
            double discriminant = b * b - 4 * a * c;

            // Check if 'a' is zero, which would not be a quadratic equation
            if (a == 0)
            {
                SplashKit.WriteLine("Coefficient a cannot be zero.");
            }
            else if (discriminant > 0)
            {
                // Two real roots
                double x1 = (-b + Sqrt(discriminant)) / (2 * a);
                double x2 = (-b - Sqrt(discriminant)) / (2 * a);
                SplashKit.WriteLine("Real roots:");
                SplashKit.WriteLine("x1 = " + x1);
                SplashKit.WriteLine("x2 = " + x2);
            }
            else if (discriminant == 0)
            {
                // One real root
                double x = -b / (2 * a);
                SplashKit.WriteLine("One real root:");
                SplashKit.WriteLine("x = " + x);
            }
            else
            {
                // Complex roots
                double realPart = -b / (2 * a);
                double imaginaryPart = Sqrt(-discriminant) / (2 * a);
                SplashKit.WriteLine("Complex roots:");
                SplashKit.WriteLine("x1 = " + realPart + " + " + imaginaryPart + "i");
                SplashKit.WriteLine("x2 = " + realPart + " - " + imaginaryPart + "i");
            }
        }
    }
}