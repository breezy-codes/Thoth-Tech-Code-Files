using SplashKitSDK;
using static SplashKitSDK.SplashKit;

char ToHex(char num)
{
    const string hexChars = "0123456789ABCDEF";
    return hexChars[num & 0xF];
}

string UrlEncode(string input)
{
    string encodedString = "";
    foreach (char character in input)
    {
        if (char.IsLetterOrDigit(character) || character == '-' || character == '_' || character == '.' || character == '~')
        {
            encodedString += character;
        }
        else
        {
            encodedString += '%';
            encodedString += ToHex((char)(character >> 4));
            encodedString += ToHex((char)(character & 0xF));
        }
    }
    return encodedString;
}

string url = "https://www.example.com/search?q=hello world";
string encodedUrl = UrlEncode(url);
WriteLine("URL Encode (" + url + "): " + UrlEncode(url));