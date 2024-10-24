using SplashKitSDK;

namespace ModularArithmetic
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

            // Ensure a valid operation is entered
            char ReadValidOperation()
            {
                char operation;
                string input;

                do
                {
                    SplashKit.Write("Enter an operation (+, -, *, ^): ");
                    input = SplashKit.ReadLine();
                    operation = input[0];

                    if (operation != '+' && operation != '-' && operation != '*' && operation != '^')
                    {
                        SplashKit.WriteLine("Invalid operation. Please enter a valid operation (+, -, *, ^).");
                    }
                } while (operation != '+' && operation != '-' && operation != '*' && operation != '^');

                return operation;
            }

            // Calculate the modular exponentiation of a number
            int ModularExponentiation(int baseNum, int exponent, int mod)
            {
                int result = 1;
                baseNum = baseNum % mod;

                while (exponent > 0)
                {
                    if (exponent % 2 == 1)
                        result = (result * baseNum) % mod;

                    exponent = exponent >> 1;
                    baseNum = (baseNum * baseNum) % mod;
                }
                return result;
            }

            // Main logic
            int mod = ReadValidInteger("Enter the modulus: ");
            int a = ReadValidInteger("Enter the first number: ");
                
            // Validate and read the operation
            char operation = ReadValidOperation();

            int b = ReadValidInteger("Enter the second number: ");

            int result;

            switch (operation)
            {
                case '+':
                    result = (a + b) % mod;
                    break;
                case '-':
                    result = (a - b + mod) % mod;
                    break;
                case '*':
                    result = (a * b) % mod;
                    break;
                case '^':
                    result = ModularExponentiation(a, b, mod);
                    break;
                default:
                    return;
            }

            SplashKit.WriteLine("Result: " + result);
        }
    }
}