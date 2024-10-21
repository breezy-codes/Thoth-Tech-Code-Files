using static SplashKitSDK.SplashKit;

// Pre-specified number as a string
string input = "5.5";
WriteLine("String input: " + input);

// Convert input string to double
double number = ConvertToDouble(input);

// Calculate the square of the number
double square = number * number;

WriteLine("The square of the number is: " + square);
