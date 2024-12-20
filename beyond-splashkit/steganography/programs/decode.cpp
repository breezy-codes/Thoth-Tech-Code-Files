#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

string base64_decode(const string &input)
{
    const string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
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

string extract_message(const vector<char>& data, int offset) {
    // Extract the length of the base64 encoded message
    int base64_length = 0;
    for (int i = 0; i < 32; ++i) {
        base64_length = (base64_length << 1) | (data[offset + i] & 1);
    }
    cout << "Extracted Base64 length (in characters): " << base64_length << endl;

    // Extract the binary message
    string binary_message;
    for (int i = 0; i < base64_length * 8; ++i) {
        binary_message += to_string(data[offset + 32 + i] & 1);
    }

    // Convert binary message to base64 string
    string base64_message;
    for (size_t i = 0; i < binary_message.length(); i += 8) {
        if (i + 8 <= binary_message.length()) {
            char character = 0;
            for (int j = 0; j < 8; ++j) {
                character = (character << 1) | (binary_message[i + j] - '0');
            }
            base64_message += character;
        }
    }

    cout << "Extracted Base64 message: " << base64_message << endl;
    cout << "Extracted Binary message: " << binary_message << endl;

    return base64_decode(base64_message);
}

int main()
{
    string path = "/home/breezy/Documents/GitHub/Small-Projects/Thoth-Tech-Code-Files/steganography";
    string encoded_file_path = path + "/encoded.bmp";
    
    ifstream input_file(encoded_file_path, ios::binary);
    vector<char> data;
    char ch;
    while (input_file.get(ch)) {
        data.push_back(ch);
    }
    input_file.close();

    int pixel_data_offset = *reinterpret_cast<int*>(&data[10]);
    cout << "Pixel data offset: " << pixel_data_offset << endl;

    string hidden_message = extract_message(data, pixel_data_offset);
    cout << "Extracted message: " << hidden_message << endl;

    return 0;
}
