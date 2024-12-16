using System;
using System.Collections.Generic;
using System.Text;

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

    static string EncodeToMorse(string text)
    {
        StringBuilder encodedMessage = new StringBuilder();
        foreach (char c in text)
        {
            char upperC = char.ToUpper(c);
            if (MORSE_CODE_DICT.ContainsKey(upperC))
            {
                encodedMessage.Append(MORSE_CODE_DICT[upperC] + " ");
            }
            else
            {
                encodedMessage.Append("? ");
            }
        }
        if (encodedMessage.Length > 0)
        {
            encodedMessage.Length--;  // Remove the trailing space
        }
        return encodedMessage.ToString();
    }

    static void Main()
    {
        Console.WriteLine("Enter the text to encode using morse code:");
        string? text = Console.ReadLine();
        if (text == null)
        {
            Console.WriteLine("No input provided.");
            return;
        }
        string encodedText = EncodeToMorse(text);
        Console.WriteLine("Each Morse code character is separated by a space, and each word is separated by a /");
        Console.WriteLine($"The Morse code for '{text}' is:");
        Console.WriteLine(encodedText);
    }
}