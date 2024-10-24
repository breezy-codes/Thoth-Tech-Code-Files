using static SplashKitSDK.SplashKit;

string text = "Hello World, hello world";
string subtext = "World";

WriteLine("Text: " + text);
WriteLine("Subtext: " + subtext);

// Check if the text contains the subtext
if (Contains(text, subtext))
{
    WriteLine("Text contains 'World'.");
}
else
{
    WriteLine("Text does not contain 'World'.");
}