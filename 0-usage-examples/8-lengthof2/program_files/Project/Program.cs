using static SplashKitSDK.SplashKit;

WriteLine("Please enter a string:");
string input = ReadLine();

// Get the length of the input string
int length = LengthOf(input);

WriteLine("The length of the input string is: " + length);
