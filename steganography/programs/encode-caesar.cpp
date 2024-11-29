#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <sstream>

using namespace std;

string caesar_cipher_encode(const string &input, int shift)
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

string base64_encode(const string &input)
{
    string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
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
    // Ask the user for the Caesar cipher shift
    int shift;
    cout << "Enter the shift for the Caesar cipher: ";
    cin >> shift;
    cin.ignore(); // Ignore the newline character left in the buffer

    // Encode the message using Caesar cipher
    string caesar_encoded_message = caesar_cipher_encode(message, shift);
    cout << "Caesar cipher encoded message: " << caesar_encoded_message << endl;

    // Encode the Caesar cipher encoded message using Base64
    string base64_message = base64_encode(caesar_encoded_message);
    cout << "Base64-encoded message: " << base64_message << endl;
    cout << "Base64 length (in characters): " << base64_message.length() << endl;

    // Convert the Base64 message to binary
    string binary_message;
    for (char ch : base64_message) {
        binary_message += bitset<8>(ch).to_string();
    }
    cout << "Binary message: " << binary_message << endl;

    // Embed the length of the Base64 message (in bytes) in the first 32 bits
    int length = base64_message.length();
    string length_bits = bitset<32>(length).to_string();
    cout << "Length bits: " << length_bits << endl;

    // Create a modifiable copy of the data
    vector<char> modified_data = data;

    // Extract original binary data at embedding positions
    string original_binary;
    for (size_t i = 0; i < length_bits.size() + binary_message.size(); ++i) {
        original_binary += bitset<8>(modified_data[offset + i]).to_string();
    }

    // Embed the message into the least significant bits
    size_t index = 0;
    for (const char& bit : length_bits + binary_message) {
        modified_data[offset + index] = (modified_data[offset + index] & 0xFE) | (bit - '0');
        index++;
    }

    // Extract modified binary data at embedding positions
    string modified_binary;
    for (size_t i = 0; i < length_bits.size() + binary_message.size(); ++i) {
        modified_binary += bitset<8>(modified_data[offset + i]).to_string();
    }

    // Truncate for readability
    auto truncate_binary = [](const string& binary_str, size_t show_bits = 64) {
        if (binary_str.length() > show_bits * 2) {
            return binary_str.substr(0, show_bits) + "..." + binary_str.substr(binary_str.length() - show_bits);
        }
        return binary_str;
    };

    cout << "\nOriginal binary data at embedding positions (truncated):" << endl;
    cout << truncate_binary(original_binary) << endl;

    cout << "\nModified binary data at embedding positions (truncated):" << endl;
    cout << truncate_binary(modified_binary) << endl;

    return modified_data;
}

void save_to_file(const vector<char>& data, const string& file_path) {
    FILE *output_file = fopen(file_path.c_str(), "wb");
    fwrite(data.data(), 1, data.size(), output_file);
    fclose(output_file);
}

int main()
{
    string path = "/home/breezy/Documents/GitHub/Small-Projects/Thoth-Tech-Code-Files/steganography";
    string input_file_path = path + "/image.bmp";
    string output_file_path = path + "/encoded.bmp";
    
    FILE *input_file = fopen(input_file_path.c_str(), "rb");
    if (!input_file) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    size_t file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    vector<char> data(file_size);
    fread(data.data(), 1, file_size, input_file);
    fclose(input_file);

    cout << "Enter the message to embed: ";
    string message_to_embed;
    getline(cin, message_to_embed);

    int pixel_data_offset = *reinterpret_cast<int*>(&data[10]);

    vector<char> encoded_data = embed_message(data, message_to_embed, pixel_data_offset);

    save_to_file(encoded_data, output_file_path);

    cout << "Message embedded successfully in Base64! Encoded image saved as " << output_file_path << "." << endl;

    return 0;
}
