using static SplashKitSDK.SplashKit;

string name = "Richard";
string location = "        Burwood";

//Convert "Richard" to "RICHARD"
name = ToUppercase(name);
WriteLine(name);

//Convert "RICHARD" to "richard"
name = ToLowercase(name);
WriteLine(name);

//Remove all of the empty spaces at the start of "       Burwood".
WriteLine("Before: " + location);
location = Trim(location);
WriteLine("After: " + location);