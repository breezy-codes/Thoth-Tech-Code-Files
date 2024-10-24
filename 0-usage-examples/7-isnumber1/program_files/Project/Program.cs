using static SplashKitSDK.SplashKit;

string[] values = { "123", "45.67", "hello", "abc", "-789", "0" };

WriteLine("Let's check if these values are numbers:");

foreach (string value in values)
{
    // Check if the string is a valid number
    bool isNumberValue = IsNumber(value);

    // Print the value along with the result using a clearer message
    if (isNumberValue)
    {
        WriteLine($"'{value}' is a valid number: true");
    }
    else
    {
        WriteLine($"'{value}' is not a valid number: false");
    }
}
