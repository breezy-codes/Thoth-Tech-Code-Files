#include "splashkit.h"
using std::to_string;

int from_hex(char hex)
{
    if (hex >= '0' && hex <= '9') return hex - '0';
    if (hex >= 'A' && hex <= 'F') return hex - 'A' + 10;
    if (hex >= 'a' && hex <= 'f') return hex - 'a' + 10;
    return -1; // Invalid hex character
}

// Function to decode a URL-encoded string
string url_decode(const string &input)
{
    string decoded_string;
    for (size_t i = 0; i < input.length(); ++i)
    {
        if (input[i] == '%')
        {
            if (i + 2 < input.length())
            {
                char hex1 = input[i + 1];
                char hex2 = input[i + 2];
                int decoded_char = (from_hex(hex1) << 4) | from_hex(hex2);
                if (decoded_char >= 0) // Only append if valid hex
                {
                    decoded_string += static_cast<char>(decoded_char);
                    i += 2; // Skip the two hex characters
                }
                else
                {
                    // Handle invalid hex gracefully (optional)
                    decoded_string += '%';
                }
            }
            else
            {
                // Handle incomplete encoding gracefully
                decoded_string += '%';
            }
        }
        else if (input[i] == '+')
        {
            decoded_string += ' '; // '+' is interpreted as space in URL encoding
        }
        else
        {
            decoded_string += input[i];
        }
    }
    return decoded_string;
}

int main()
{
    string encoded_url = "https%3A%2F%2Fwww.example.com%2Fsearch%3Fq%3Dhello%20world";
    string decoded_url = url_decode(encoded_url);
    write_line("Decoded URL: " + decoded_url);

    return 0;
}