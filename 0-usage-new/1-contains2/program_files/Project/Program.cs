using static SplashKitSDK.SplashKit;

WriteLine("Please enter a sentence:");
string sentence = ReadLine();

if (sentence.Contains("SplashKit"))
{
    WriteLine("Your sentence contains the word 'SplashKit'.");
}
else
{
    WriteLine("Your sentence does not contain 'SplashKit'.");
}