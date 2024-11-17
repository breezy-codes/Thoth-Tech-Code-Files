#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include "splashkit.h"

using std::to_string;

string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

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

vector<char> embed_message(const vector<char>& data, const string& message, int offset) {
    string base64_message = base64_encode(message);
    write_line("Base64-encoded message: " + base64_message);
    write_line("Base64 length (in characters): " + to_string(base64_message.length()));

    string binary_message;
    for (char ch : base64_message) {
        binary_message += std::bitset<8>(ch).to_string();
    }

    string length_bits = std::bitset<32>(base64_message.length()).to_string();

    vector<char> modified_data = data;
    size_t i = 0;
    for (const char& bit : length_bits + binary_message) {
        modified_data[offset + i] = (modified_data[offset + i] & 0xFE) | (bit - '0');
        i++;
    }

    return modified_data;
}

int main() {
    string path = "/home/breezy/Documents/GitHub/Small-Projects/Thoth-Tech-Code-Files/steganography";
    string input_file_path = path + "/image.bmp";
    string output_file_path = path + "/encoded.bmp";
    
    std::ifstream input_file(input_file_path, std::ios::binary);
    std::vector<char> data((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    input_file.close();

    write("Enter the message to embed: ");
    string message_to_embed = read_line();

    int pixel_data_offset = *reinterpret_cast<int*>(&data[10]);

    std::vector<char> encoded_data = embed_message(data, message_to_embed, pixel_data_offset);

    std::ofstream output_file(output_file_path, std::ios::binary);
    output_file.write(encoded_data.data(), encoded_data.size());
    output_file.close();

    write_line("Message embedded successfully in Base64! Encoded image saved as " + output_file_path + ".");

    return 0;
}
