using static SplashKitSDK.SplashKit;

WriteLine("Please enter a string:");
string input = ReadLine();

// Convert input to lowercase
string lower = ToLowercase(input);

WriteLine("Lowercase: " + lower);
