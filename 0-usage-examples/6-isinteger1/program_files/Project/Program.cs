using static SplashKitSDK.SplashKit;

string[] values = { "123", "45.67", "-50", "abc", "789", "0" };

foreach (string value in values)
{
    // Check if string is a valid integer
    bool integer = IsInteger(value);

    // Print the value along with the result using "true" or "false"
    WriteLine(value + " - " + (integer ? "true" : "false"));
}
