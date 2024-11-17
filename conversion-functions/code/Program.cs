using static SplashKitSDK.SplashKit;

using SplashKitSDK;

const string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Helper functions
bool IsBinary(string binaryString)
{
    foreach (char character in binaryString)
    {
        if (character != '0' && character != '1')
            return false;
    }
    return !string.IsNullOrEmpty(binaryString);
}

bool IsHex(string hexString)
{
    foreach (char character in hexString)
    {
        if (!((character >= '0' && character <= '9') || (character >= 'A' && character <= 'F') || (character >= 'a' && character <= 'f')))
            return false;
    }
    return !string.IsNullOrEmpty(hexString);
}

bool IsOctal(string octalString)
{
    foreach (char character in octalString)
    {
        if (character < '0' || character > '7')
            return false;
    }
    return !string.IsNullOrEmpty(octalString);
}

string DecToBin(uint decimalValue)
{
    if (decimalValue == 0) return "0";

    string binaryString = "";
    while (decimalValue > 0)
    {
        binaryString = ((decimalValue & 1) == 1 ? "1" : "0") + binaryString;
        decimalValue >>= 1;
    }
    return binaryString;
}

uint BinToDec(string binaryString)
{
    if (!IsBinary(binaryString)) return 0;

    uint decimalValue = 0;
    for (int i = 0; i < binaryString.Length; i++)
    {
        if (binaryString[i] == '1')
        {
            decimalValue += (uint)(1 << (binaryString.Length - i - 1));
        }
    }
    return decimalValue;
}

string HexToBin(string hexString)
{
    if (!IsHex(hexString)) return "";

    string binaryString = "";
    foreach (char hexChar in hexString)
    {
        int hexValue = (hexChar >= '0' && hexChar <= '9') ? hexChar - '0' :
                       (hexChar >= 'A' && hexChar <= 'F') ? hexChar - 'A' + 10 :
                       hexChar - 'a' + 10;

        for (int i = 3; i >= 0; i--)
        {
            binaryString += ((hexValue >> i) & 1) == 1 ? "1" : "0";
        }
    }
    return binaryString.TrimStart('0');
}

string BinToHex(string binaryString)
{
    if (!IsBinary(binaryString)) return "";

    string paddedBinaryString = binaryString.PadLeft((binaryString.Length + 3) / 4 * 4, '0');
    string hexString = "";

    for (int i = 0; i < paddedBinaryString.Length; i += 4)
    {
        int hexValue = 0;
        for (int j = 0; j < 4; j++)
        {
            hexValue <<= 1;
            if (paddedBinaryString[i + j] == '1')
                hexValue |= 1;
        }

        if (hexValue < 10)
            hexString += (char)('0' + hexValue);
        else
            hexString += (char)('A' + (hexValue - 10));
    }
    return hexString;
}

string DecToOct(uint decimalValue)
{
    if (decimalValue == 0) return "0";

    string octalString = "";
    while (decimalValue > 0)
    {
        octalString = (decimalValue % 8).ToString() + octalString;
        decimalValue /= 8;
    }
    return octalString;
}

uint OctToDec(string octalString)
{
    if (!IsOctal(octalString)) return 0;

    uint decimalValue = 0;
    foreach (char octChar in octalString)
    {
        decimalValue = decimalValue * 8 + (uint)(octChar - '0');
    }
    return decimalValue;
}

string OctToBin(string octalString)
{
    if (!IsOctal(octalString)) return "";

    string binaryString = "";
    foreach (char octChar in octalString)
    {
        int octValue = octChar - '0';
        for (int i = 2; i >= 0; i--)
        {
            binaryString += ((octValue >> i) & 1) == 1 ? "1" : "0";
        }
    }
    return binaryString.TrimStart('0');
}

string BinToOct(string binaryString)
{
    if (!IsBinary(binaryString)) return "";

    string paddedBinaryString = binaryString.PadLeft((binaryString.Length + 2) / 3 * 3, '0');
    string octalString = "";

    for (int i = 0; i < paddedBinaryString.Length; i += 3)
    {
        int octValue = 0;
        for (int j = 0; j < 3; j++)
        {
            octValue <<= 1;
            if (paddedBinaryString[i + j] == '1')
                octValue |= 1;
        }
        octalString += (char)('0' + octValue);
    }
    return octalString.TrimStart('0');
}

string HexToOct(string hexString) => BinToOct(HexToBin(hexString));

string OctToHex(string octalString) => BinToHex(OctToBin(octalString));

string Base64Encode(string input)
{
    string encodedString = "";
    int value = 0, bits = -6;
    const int base64Mask = 0x3F;

    foreach (char character in input)
    {
        value = (value << 8) + character;
        bits += 8;

        while (bits >= 0)
        {
            encodedString += BASE64_CHARS[(value >> bits) & base64Mask];
            bits -= 6;
        }
    }

    if (bits > -6)
    {
        encodedString += BASE64_CHARS[((value << 8) >> (bits + 8)) & base64Mask];
    }

    while (encodedString.Length % 4 != 0)
    {
        encodedString += '=';
    }
    return encodedString;
}

string Base64Decode(string input)
{
    string decodedString = "";
    int value = 0, bits = -8;

    foreach (char character in input)
    {
        if (character == '=') break;
        if (BASE64_CHARS.IndexOf(character) == -1) continue;

        value = (value << 6) + BASE64_CHARS.IndexOf(character);
        bits += 6;

        if (bits >= 0)
        {
            decodedString += (char)((value >> bits) & 0xFF);
            bits -= 8;
        }
    }
    return decodedString;
}

// Main program using SplashKit
WriteLine("Testing Binary Functions:");
WriteLine($"Binary to Decimal (1010): {BinToDec("1010")}");
WriteLine($"Decimal to Binary (10): {DecToBin(10)}");

WriteLine("\nTesting Hexadecimal Functions:");
WriteLine($"Hex to Binary (A): {HexToBin("A")}");
WriteLine($"Binary to Hex (1010): {BinToHex("1010")}");

WriteLine("\nTesting Octal Functions:");
WriteLine($"Octal to Decimal (12): {OctToDec("12")}");
WriteLine($"Decimal to Octal (10): {DecToOct(10)}");
WriteLine($"Octal to Binary (12): {OctToBin("12")}");
WriteLine($"Binary to Octal (1010): {BinToOct("1010")}");
WriteLine($"Hex to Octal (A): {HexToOct("A")}");
WriteLine($"Octal to Hex (12): {OctToHex("12")}");

WriteLine("\nTesting Base64 Functions:");
string plainText = "Hello";
string encoded = Base64Encode(plainText);
WriteLine($"Base64 Encode ({plainText}): {encoded}");
WriteLine($"Base64 Decode ({encoded}): {Base64Decode(encoded)}");

WriteLine("\nTesting Validation Functions:");
WriteLine($"Is Binary (1010): {IsBinary("1010")}");
WriteLine($"Is Hex (A): {IsHex("A")}");
WriteLine($"Is Octal (12): {IsOctal("12")}");
