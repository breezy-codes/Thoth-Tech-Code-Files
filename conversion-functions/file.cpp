#include "splashkit.h"
using std::string;
using std::to_string;
const string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

bool is_binary(const string &binary_string)
{
    for (char character : binary_string)
    {
        if (character != '0' && character != '1')
            return false;
    }
    return !binary_string.empty();
}

bool is_hex(const string &hex_string)
{
    for (char character : hex_string)
    {
        if (!((character >= '0' && character <= '9') || (character >= 'A' && character <= 'F') || (character >= 'a' && character <= 'f')))
            return false;
    }
    return !hex_string.empty();
}

bool is_octal(const string &octal_string)
{
    for (char character : octal_string)
    {
        if (character < '0' || character > '7')
            return false;
    }
    return !octal_string.empty();
}

string dec_to_bin(unsigned int decimal_value)
{
    if (decimal_value == 0)
        return "0";

    string binary_string;
    while (decimal_value > 0)
    {
        binary_string = ((decimal_value & 1) ? "1" : "0") + binary_string;
        decimal_value >>= 1;
    }
    return binary_string;
}

unsigned int bin_to_dec(const string &binary_string)
{
    if (!is_binary(binary_string))
    {
        return 0;
    }

    unsigned int decimal_value = 0;
    for (size_t i = 0; i < binary_string.size(); i++)
    {
        if (binary_string[i] == '1')
        {
            decimal_value += (1 << (binary_string.size() - i - 1));
        }
    }
    return decimal_value;
}

string hex_to_bin(const string &hex_string)
{
    if (!is_hex(hex_string))
    {
        return "";
    }

    string binary_string;
    for (char hex_character : hex_string)
    {
        int hex_value = 0;

        if (hex_character >= '0' && hex_character <= '9')
            hex_value = hex_character - '0';
        else if (hex_character >= 'A' && hex_character <= 'F')
            hex_value = hex_character - 'A' + 10;
        else if (hex_character >= 'a' && hex_character <= 'f')
            hex_value = hex_character - 'a' + 10;

        for (int i = 3; i >= 0; i--)
        {
            binary_string += ((hex_value >> i) & 1) ? '1' : '0';
        }
    }

    if (hex_string.length() == 1)
    {
        size_t first_one = binary_string.find_first_not_of('0');
        return (first_one == string::npos) ? "0" : binary_string.substr(first_one);
    }

    return binary_string;
}

string bin_to_hex(const string &binary_string)
{
    if (!is_binary(binary_string))
    {
        return "";
    }

    string hex_string;
    int length = binary_string.length();

    int padding = (4 - (length % 4)) % 4;
    string padded_binary_string = string(padding, '0') + binary_string;

    for (size_t i = 0; i < padded_binary_string.length(); i += 4)
    {
        int hex_value = 0;
        for (size_t j = 0; j < 4; j++)
        {
            hex_value <<= 1;
            if (padded_binary_string[i + j] == '1')
                hex_value |= 1;
        }

        if (hex_value < 10)
            hex_string += '0' + hex_value;
        else
            hex_string += 'A' + (hex_value - 10);
    }
    return hex_string;
}

string dec_to_oct(unsigned int decimal_value)
{
    if (decimal_value == 0)
        return "0";

    string octal_string;
    while (decimal_value > 0)
    {
        octal_string = to_string(decimal_value % 8) + octal_string;
        decimal_value /= 8;
    }
    return octal_string;
}

unsigned int oct_to_dec(const string &octal_string)
{
    if (!is_octal(octal_string))
    {
        return 0;
    }

    unsigned int decimal_value = 0;
    for (size_t i = 0; i < octal_string.size(); i++)
    {
        decimal_value = decimal_value * 8 + (octal_string[i] - '0');
    }
    return decimal_value;
}

string oct_to_bin(const string &octal_string)
{
    if (!is_octal(octal_string))
    {
        return "";
    }

    string binary_string;
    for (char octal_character : octal_string)
    {
        int octal_value = octal_character - '0';

        for (int i = 2; i >= 0; i--)
        {
            binary_string += ((octal_value >> i) & 1) ? '1' : '0';
        }
    }

    size_t first_one = binary_string.find_first_not_of('0');
    return (first_one == string::npos) ? "0" : binary_string.substr(first_one);
}

string bin_to_oct(const string &binary_string)
{
    if (!is_binary(binary_string))
    {
        return "";
    }

    string octal_string;

    int padding = (3 - (binary_string.length() % 3)) % 3;
    string padded_binary_string = string(padding, '0') + binary_string;

    for (size_t i = 0; i < padded_binary_string.length(); i += 3)
    {
        int octal_value = 0;
        for (size_t j = 0; j < 3; j++)
        {
            octal_value <<= 1;
            if (padded_binary_string[i + j] == '1')
                octal_value |= 1;
        }

        octal_string += '0' + octal_value;
    }

    size_t first_non_zero = octal_string.find_first_not_of('0');
    return (first_non_zero == string::npos) ? "0" : octal_string.substr(first_non_zero);
}

string hex_to_oct(const string &hex_string)
{
    if (!is_hex(hex_string))
    {
        return "";
    }

    string binary_string = hex_to_bin(hex_string);
    return bin_to_oct(binary_string);
}

string oct_to_hex(const string &octal_string)
{
    if (!is_octal(octal_string))
    {
        return "";
    }

    string binary_string = oct_to_bin(octal_string);
    return bin_to_hex(binary_string);
}

string base64_encode(const string &input)
{
    string encoded_string;
    int value = 0, bits = -6;
    const unsigned int base64_mask = 0x3F;

    for (unsigned char character : input)
    {
        value = (value << 8) + character;
        bits += 8;

        while (bits >= 0)
        {
            encoded_string.push_back(BASE64_CHARS[(value >> bits) & base64_mask]);
            bits -= 6;
        }
    }

    if (bits > -6)
    {
        encoded_string.push_back(BASE64_CHARS[((value << 8) >> (bits + 8)) & base64_mask]);
    }

    while (encoded_string.size() % 4)
    {
        encoded_string.push_back('='); // Padding to make the length a multiple of 4
    }

    return encoded_string;
}

string base64_decode(const string &input)
{
    string decoded_string;
    int value = 0, bits = -8;
    for (unsigned char character : input)
    {
        if (BASE64_CHARS.find(character) == string::npos)
        {
            if (character == '=')
                break; // Padding character, stop decoding
            continue;  // Ignore any characters not in Base64 alphabet
        }

        value = (value << 6) + BASE64_CHARS.find(character);
        bits += 6;

        if (bits >= 0)
        {
            decoded_string.push_back(char((value >> bits) & 0xFF));
            bits -= 8;
        }
    }
    return decoded_string;
}

int main()
{
    // Test binary functions
    write_line("Testing Binary Functions:");
    string bin = "1010";
    write_line("Binary to Decimal (" + bin + "): " + to_string(bin_to_dec(bin)));
    unsigned int dec = 10;
    write_line("Decimal to Binary (" + to_string(dec) + "): " + dec_to_bin(dec));

    // Test hexadecimal functions
    write_line("\nTesting Hexadecimal Functions:");
    string hex = "A";
    write_line("Hex to Binary (" + hex + "): " + hex_to_bin(hex));
    string bin_from_hex = "1010";
    write_line("Binary to Hex (" + bin_from_hex + "): " + bin_to_hex(bin_from_hex));

    // Test octal functions
    write_line("\nTesting Octal Functions:");
    string oct = "12";
    write_line("Octal to Decimal (" + oct + "): " + to_string(oct_to_dec(oct)));
    write_line("Decimal to Octal (" + to_string(dec) + "): " + dec_to_oct(dec));
    write_line("Octal to Binary (" + oct + "): " + oct_to_bin(oct));
    write_line("Binary to Octal (" + bin + "): " + bin_to_oct(bin));
    write_line("Hex to Octal (" + hex + "): " + hex_to_oct(hex));
    write_line("Octal to Hex (" + oct + "): " + oct_to_hex(oct));

    // Test Base64 functions
    write_line("\nTesting Base64 Functions:");
    string plain_text = "Hello";
    string encoded = base64_encode(plain_text);
    write_line("Base64 Encode (" + plain_text + "): " + encoded);
    string decoded = base64_decode(encoded);
    write_line("Base64 Decode (" + encoded + "): " + decoded);

    // Validation functions
    write_line("\nTesting Validation Functions:");
    write_line("Is Binary (" + bin + "): " + (is_binary(bin) ? "True" : "False"));
    write_line("Is Hex (" + hex + "): " + (is_hex(hex) ? "True" : "False"));
    write_line("Is Octal (" + oct + "): " + (is_octal(oct) ? "True" : "False"));
}