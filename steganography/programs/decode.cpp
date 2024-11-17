#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include "splashkit.h"

using std::to_string;

const std::string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

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

std::string extract_message(const std::vector<char>& data, int offset) {
    std::string length_bits;
    for (int i = 0; i < 32; ++i) {
        length_bits += std::to_string(data[offset + i] & 1);
    }

    int base64_length = std::bitset<32>(length_bits).to_ulong();
    std::cout << "Extracted Base64 length (in characters): " << base64_length << std::endl;

    std::string binary_message;
    for (int i = 0; i < base64_length * 8; ++i) {
        binary_message += std::to_string(data[offset + 32 + i] & 1);
    }

    std::string base64_message;
    for (size_t i = 0; i < binary_message.length(); i += 8) {
        if (i + 8 <= binary_message.length()) {
            base64_message += static_cast<char>(std::bitset<8>(binary_message.substr(i, 8)).to_ulong());
        }
    }

    return base64_decode(base64_message);
}

int main() {
    std::string path = "/home/breezy/Documents/GitHub/Small-Projects/Thoth-Tech-Code-Files/steganography";
    std::string encoded_file_path = path + "/encoded.bmp";
    
    std::ifstream input_file(encoded_file_path, std::ios::binary);
    std::vector<char> data((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    input_file.close();

    int pixel_data_offset = *reinterpret_cast<int*>(&data[10]);
    std::cout << "Pixel data offset: " << pixel_data_offset << std::endl;

    std::string hidden_message = extract_message(data, pixel_data_offset);
    std::cout << "Extracted message: " << hidden_message << std::endl;

    return 0;
}
