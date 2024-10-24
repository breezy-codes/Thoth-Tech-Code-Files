using static SplashKitSDK.SplashKit;

WriteLine("Please enter a value:");
string input = ReadLine();

// Check if the input is a valid integer
bool value = IsInteger(input);

if (value)
{
    WriteLine("The input is a valid integer.");
}
else
{
    WriteLine("The input is not a valid integer.");
}