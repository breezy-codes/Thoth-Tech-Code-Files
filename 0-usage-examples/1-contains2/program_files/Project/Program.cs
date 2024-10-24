using static SplashKitSDK.SplashKit;

WriteLine("Please enter a sentence:");
string sentence = ReadLine();
string subtext = "SplashKit";

if (Contains(sentence, subtext))
{
    WriteLine("Your sentence contains the word 'SplashKit'.");
}
else
{
    WriteLine("Your sentence does not contain 'SplashKit'.");
}