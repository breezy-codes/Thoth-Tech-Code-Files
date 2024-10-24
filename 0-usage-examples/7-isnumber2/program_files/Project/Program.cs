using static SplashKitSDK.SplashKit;

WriteLine("Please enter a value:");
string input = ReadLine();

// Check if the input is a number
bool value = IsNumber(input);

if (value)
{
    WriteLine("The input is a number.");
}
else
{
    WriteLine("The input is not a number.");
}