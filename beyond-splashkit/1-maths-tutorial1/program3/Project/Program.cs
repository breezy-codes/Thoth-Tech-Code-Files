using SplashKitSDK;
using static SplashKitSDK.SplashKit;

// Ensure the user enters a valid integer
int ReadValidInteger(string prompt)
{
    int number;
    Write(prompt);
    string input = ReadLine();

    while (!IsInteger(input))
    {
        WriteLine("Invalid integer input. Please enter a valid integer.");
        Write(prompt);
        input = ReadLine();
    }

    number = ConvertToInteger(input);
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

// Calculate the least common multiple of two numbers
int Lcm(int a, int b)
{
    return Math.Abs(a * b) / Gcd(a, b);
}

// Main logic
int num1 = ReadValidInteger("Enter the first integer: ");
int num2 = ReadValidInteger("Enter the second integer: ");

int result = Lcm(num1, num2);
WriteLine("The LCM of " + num1 + " and " + num2 + " is " + result);
