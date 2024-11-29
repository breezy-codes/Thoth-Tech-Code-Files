using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

class Program
{
    static string Base64Encode(string input)
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

    static List<byte> EmbedMessage(List<byte> data, string message, int offset)
    {
        string base64Message = Base64Encode(message);
        Console.WriteLine("Base64-encoded message: " + base64Message);
        Console.WriteLine("Base64 length (in characters): " + base64Message.Length);

        StringBuilder binaryMessage = new StringBuilder();
        foreach (char ch in base64Message)
        {
            binaryMessage.Append(Convert.ToString(ch, 2).PadLeft(8, '0'));
        }

        StringBuilder lengthBits = new StringBuilder();
        int length = base64Message.Length;
        for (int j = 31; j >= 0; --j) // Renamed loop variable from 'i' to 'j'
        {
            lengthBits.Append((length >> j) & 1);
        }

        List<byte> modifiedData = new List<byte>(data);
        int bitIndex = 0; // Renamed from 'i' to 'bitIndex'
        foreach (char bit in lengthBits.ToString() + binaryMessage.ToString())
        {
            modifiedData[offset + bitIndex] = (byte)((modifiedData[offset + bitIndex] & 0xFE) | (bit - '0'));
            bitIndex++;
        }

        return modifiedData;
    }

    static void SaveToFile(List<byte> data, string filePath)
    {
        File.WriteAllBytes(filePath, data.ToArray());
    }

    static void Main()
    {
        string path = "/home/breezy/Documents/GitHub/Small-Projects/Thoth-Tech-Code-Files/steganography";
        string inputFilePath = Path.Combine(path, "image.bmp");
        string outputFilePath = Path.Combine(path, "encoded.bmp");

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
    }
}