using static SplashKitSDK.SplashKit;

//User input will initially be stored in these two strings.
string snum_1, snum_2;

// And then it will be converted and stored in these integers.
int inum_1, inum_2, result;

//Read user input
Write("Enter first number: ");
snum_1 = ReadLine();
Write("Enter second number: ");
snum_2 = ReadLine();

//Convert user input to integers
inum_1 = ConvertToInteger(snum_1);
inum_2 = ConvertToInteger(snum_2);

//Compute the result
result = inum_1 * inum_2;

//Output the results
Write(snum_1 + " multiplied by " + snum_2 + " equals ");
WriteLine(result);