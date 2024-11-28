#include "splashkit.h"
using std::to_string;

string ceaser_cipher_encode(const string &input, int shift)
{
    string encoded_string;
    for (char character : input)
    {
        if (isalpha(character))
        {
            char base = islower(character) ? 'a' : 'A';
            encoded_string += (character - base + shift) % 26 + base;
        }
        else
        {
            encoded_string += character; // Non-alphabet characters remain unchanged
        }
    }
    return encoded_string;
}

string ceaser_cipher_decode(const string &input, int shift)
{
    return ceaser_cipher_encode(input, 26 - (shift % 26)); // Reverse the shift
}

void ceaser_cipher_brute_force(const string &input)
{
    for (int shift = 0; shift < 26; shift++)
    {
        write_line("Shift " + to_string(shift) + "=> " + ceaser_cipher_decode(input, shift));
    }
}

int main()
{
    write_line("Enter the encoded message: ");
    string encoded_message = read_line();
    ceaser_cipher_brute_force(encoded_message);
}