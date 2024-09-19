using static SplashKitSDK.SplashKit;

//Convert the string "2017" to an integer 2017
string some_string = "2017";
int some_number = ConvertToInteger(some_string);

Write("The value of some_number is: ");
WriteLine(some_number);

//Convert the string "3.14159265358979" to a double ~3.141593
string pi_string = "3.14159265358979";
double pi = ConvertToDouble(pi_string);

Write("The value of pi is: ");
WriteLine(pi);