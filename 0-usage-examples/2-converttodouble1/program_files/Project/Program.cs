using static SplashKitSDK.SplashKit;

WriteLine("Please enter a number to convert to a double:");
string value = ReadLine();

// Convert string to double
double result = ConvertToDouble(value);

WriteLine("The value as a double is: " + result);
