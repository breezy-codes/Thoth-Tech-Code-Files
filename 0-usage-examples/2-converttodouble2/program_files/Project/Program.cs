using static SplashKitSDK.SplashKit;

WriteLine("Please enter a number:");
string input = ReadLine();

// Convert input string to double
double number = ConvertToDouble(input);

// Calculate the square of the number
double square = number * number;

WriteLine("The square of the number is: " + square);
