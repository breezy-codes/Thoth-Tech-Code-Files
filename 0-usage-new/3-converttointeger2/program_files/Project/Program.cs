using static SplashKitSDK.SplashKit;

WriteLine("Please enter a number:");
string input = ReadLine();

// Convert input string to integer
int number = ConvertToInteger(input);

// Check if the number is odd or even
if (number % 2 == 0)
{
    WriteLine("The number is even.");
}
else
{
    WriteLine("The number is odd.");
}
