using System;
using System.Collections.Generic;

class Program
{
    
    static Dictionary<string, char> morseCodeDict = new Dictionary<string, char>
    {
        { ".-", 'A' }, { "-...", 'B' }, { "-.-.", 'C' }, { "-..", 'D' },
        { ".", 'E' }, { "..-.", 'F' }, { "--.", 'G' }, { "....", 'H' },
        { "..", 'I' }, { ".---", 'J' }, { "-.-", 'K' }, { ".-..", 'L' },
        { "--", 'M' }, { "-.", 'N' }, { "---", 'O' }, { ".--.", 'P' },
        { "--.-", 'Q' }, { ".-.", 'R' }, { "...", 'S' }, { "-", 'T' },
        { "..-", 'U' }, { "...-", 'V' }, { ".--", 'W' }, { "-..-", 'X' },
        { "-.--", 'Y' }, { "--..", 'Z' }, { "-----", '0' }, { ".----", '1' },
        { "..---", '2' }, { "...--", '3' }, { "....-", '4' }, { ".....", '5' },
        { "-....", '6' }, { "--...", '7' }, { "---..", '8' }, { "----.", '9' },
        { "--..--", ',' }, { ".-.-.-", '.' }, { "..--..", '?' }, { ".----.", '\'' },
        { "-.-.--", '!' }, { "-..-.", '/' }, { "-.--.", '(' }, { "-.--.-", ')' },
        { ".-...", '&' }, { "---...", ':' }, { "-.-.-.", ';' }, { "-...-", '=' },
        { ".-.-.", '+' }, { "-....-", '-' }, { "..--.-", '_' }, { ".-..-.", '"' },
        { "...-..-", '$' }, { ".--.-.", '@' }, { "/", ' ' }
    };

    static string DecodeFromMorse(string morseCode)
    {
        var decodedMessage = new List<char>();
        var codes = morseCode.Split(' ');

        foreach (var code in codes)
        {
            if (morseCodeDict.TryGetValue(code, out char character))
            {
                decodedMessage.Add(character);
            }
            else
            {
                decodedMessage.Add('?');  // Unknown Morse code
            }
        }

        return new string(decodedMessage.ToArray());
    }

    static void Main()
    {
        Console.WriteLine("Enter the Morse code to decode:");
        string? text = Console.ReadLine();
        if (text == null)
        {
            Console.WriteLine("No input provided.");
            return;
        }
        string decodedText = DecodeFromMorse(text);
        Console.WriteLine("Each Morse code character is separated by a space, and each word is separated by a /");
        Console.WriteLine($"The decoded text for '{text}' is: {decodedText}");
    }
}