using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

string path = "/home/breezy/Documents/GitHub/Small-Projects/Thoth-Tech-Code-Files/steganography";
string encodedFilePath = Path.Combine(path, "encoded.bmp");

string Base64Decode(string input)
{
    string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
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

string ExtractMessage(List<byte> data, int offset)
{
    // Extract the length of the Base64 encoded message
    int base64Length = 0;
    for (int i = 0; i < 32; ++i)
    {
        base64Length = (base64Length << 1) | (data[offset + i] & 1);
    }
    Console.WriteLine($"Extracted Base64 length (in characters): {base64Length}");

    // Extract the binary message
    StringBuilder binaryMessage = new StringBuilder();
    for (int i = 0; i < base64Length * 8; ++i)
    {
        binaryMessage.Append(data[offset + 32 + i] & 1);
    }

    // Convert binary message to Base64 string
    StringBuilder base64Message = new StringBuilder();
    for (int i = 0; i < binaryMessage.Length; i += 8)
    {
        if (i + 8 <= binaryMessage.Length)
        {
            char character = (char)0;
            for (int j = 0; j < 8; ++j)
            {
                character = (char)((character << 1) | (binaryMessage[i + j] - '0'));
            }
            base64Message.Append(character);
        }
    }

    Console.WriteLine($"Extracted Base64 message: {base64Message}");
    Console.WriteLine($"Extracted Binary message: {binaryMessage}");

    return Base64Decode(base64Message.ToString());
}

if (!File.Exists(encodedFilePath))
{
    Console.WriteLine("Encoded file not found.");
    return;
}

// Read the file into a byte list
List<byte> data = new List<byte>(File.ReadAllBytes(encodedFilePath));

// Get the pixel data offset
int pixelDataOffset = BitConverter.ToInt32(data.ToArray(), 10);
Console.WriteLine($"Pixel data offset: {pixelDataOffset}");

// Extract and decode the hidden message
string hiddenMessage = ExtractMessage(data, pixelDataOffset);
Console.WriteLine($"Extracted message: {hiddenMessage}");
