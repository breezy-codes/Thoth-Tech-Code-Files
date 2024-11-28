using SplashKitSDK;
using static SplashKitSDK.SplashKit;

// Calculate the square root of a number
double Sqrt(double x)
{
    double y = 0.0;
    int p = 0;
    int c = 0;

    // Find the first perfect square greater than the input number
    while (true)
    {
        p++;
        int square = (p + 1) * (p + 1); // Calculate the next perfect square
        if (x <= square) // Stop when x is less than or equal to the square
            break;
    }

    // Approximate the square root using the Newton-Raphson method
    y = (double)p;
    c = 0;
    while (c < 10) // Perform a maximum of 10 iterations
    {
        y = (x / y + y) / 2; // Update the guess by averaging x/y and y

        if (y * y == x) // Check if the square of the current guess matches the input
            return y; // If exact, return the square root

        c++;
    }

    return y;
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

// Main logic
int number = ReadValidInteger("Enter an integer: ");

if (IsPrime(number))
{
    WriteLine(number + " is a prime number.");
}
else
{
    WriteLine(number + " is not a prime number.");
}

// print the square root of the number
WriteLine($"The square root of {number} is {Sqrt(number)}");