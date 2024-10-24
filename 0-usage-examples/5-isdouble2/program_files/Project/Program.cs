using static SplashKitSDK.SplashKit;

WriteLine("Please enter a value:");
string input = ReadLine();

// Check if the input is a valid double
bool value = IsDouble(input);

if (value)
{
    WriteLine("The input is a valid double.");
}
else
{
    WriteLine("The input is not a valid double.");
}