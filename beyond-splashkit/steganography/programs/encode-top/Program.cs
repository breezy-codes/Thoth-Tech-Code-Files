﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

string path = "/home/breezy/Documents/GitHub/Small-Projects/Thoth-Tech-Code-Files/steganography";
string inputFilePath = Path.Combine(path, "image.bmp");
string outputFilePath = Path.Combine(path, "encoded.bmp");

string Base64Encode(string input)
{
    string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
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

// This will allow us to highlight the differences in the binary data
(string, string) HighlightChanges(string original, string modified)
{
    StringBuilder highlightedOriginal = new StringBuilder();
    StringBuilder highlightedModified = new StringBuilder();

    for (int i = 0; i < original.Length; i++)
    {
        if (original[i] != modified[i])
        {
            highlightedOriginal.Append($"[{original[i]}]");
            highlightedModified.Append($"[{modified[i]}]");
        }
        else
        {
            highlightedOriginal.Append(original[i]);
            highlightedModified.Append(modified[i]);
        }
    }

    return (highlightedOriginal.ToString(), highlightedModified.ToString());
}

List<byte> EmbedMessage(List<byte> data, string message, int offset)
{
    // Encode the message using Base64
    string base64Message = Base64Encode(message);
    Console.WriteLine("Base64-encoded message: " + base64Message);
    Console.WriteLine("Base64 length (in characters): " + base64Message.Length);

    // Convert the Base64 message to binary
    StringBuilder binaryMessage = new StringBuilder();
    foreach (char ch in base64Message)
    {
        binaryMessage.Append(Convert.ToString(ch, 2).PadLeft(8, '0'));
    }
    Console.WriteLine("Binary message: " + binaryMessage);

    // Embed the length of the Base64 message (in bytes) in the first 32 bits
    StringBuilder lengthBits = new StringBuilder();
    int length = base64Message.Length;
    for (int j = 31; j >= 0; --j)
    {
        lengthBits.Append((length >> j) & 1);
    }
    Console.WriteLine("Length bits: " + lengthBits);

    // Create a modifiable copy of the data
    List<byte> modifiedData = new List<byte>(data);

    // Extract original binary data at embedding positions
    StringBuilder originalBinary = new StringBuilder();
    for (int i = 0; i < lengthBits.Length + binaryMessage.Length; i++)
    {
        originalBinary.Append(Convert.ToString(modifiedData[offset + i], 2).PadLeft(8, '0'));
    }

    // Embed the message into the least significant bits
    int bitIndex = 0;
    foreach (char bit in lengthBits.ToString() + binaryMessage.ToString())
    {
        modifiedData[offset + bitIndex] = (byte)((modifiedData[offset + bitIndex] & 0xFE) | (bit - '0'));
        bitIndex++;
    }

    // Extract modified binary data at embedding positions
    StringBuilder modifiedBinary = new StringBuilder();
    for (int i = 0; i < lengthBits.Length + binaryMessage.Length; i++)
    {
        modifiedBinary.Append(Convert.ToString(modifiedData[offset + i], 2).PadLeft(8, '0'));
    }

    // Highlight changes
    (string highlightedOriginal, string highlightedModified) = HighlightChanges(originalBinary.ToString(), modifiedBinary.ToString());

    // Truncate for readability
    string TruncateBinary(string binaryStr, int showBits = 64)
    {
        if (binaryStr.Length > showBits * 2)
        {
            return binaryStr.Substring(0, showBits) + "..." + binaryStr.Substring(binaryStr.Length - showBits);
        }
        return binaryStr;
    }

    Console.WriteLine("\nOriginal binary data at embedding positions (truncated):");
    Console.WriteLine(TruncateBinary(highlightedOriginal));

    Console.WriteLine("\nModified binary data at embedding positions (truncated):");
    Console.WriteLine(TruncateBinary(highlightedModified));

    return modifiedData;
}

void SaveToFile(List<byte> data, string filePath)
{
    File.WriteAllBytes(filePath, data.ToArray());
}

if (!File.Exists(inputFilePath))
{
    Console.WriteLine("Error opening input file.");
    return;
}

List<byte> data = new List<byte>(File.ReadAllBytes(inputFilePath));

Console.WriteLine("Enter the message to embed: ");
string? messageToEmbed = Console.ReadLine();

if (string.IsNullOrEmpty(messageToEmbed))
{
    Console.WriteLine("Message cannot be empty.");
    return;
}

int pixelDataOffset = BitConverter.ToInt32(data.ToArray(), 10);

List<byte> encodedData = EmbedMessage(data, messageToEmbed, pixelDataOffset);

SaveToFile(encodedData, outputFilePath);

Console.WriteLine("Message embedded successfully in Base64! Encoded image saved as " + outputFilePath + ".");
