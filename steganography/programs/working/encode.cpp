#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>

const std::string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string base64_encode(const std::string &input) {
    std::string binary_data;
    for (char ch : input) {
        binary_data += std::bitset<8>(ch).to_string();
    }

    while (binary_data.length() % 6 != 0) {
        binary_data += '0';
    }

    std::string encoded;
    for (size_t i = 0; i < binary_data.length(); i += 6) {
        encoded += BASE64_CHARS[std::bitset<6>(binary_data.substr(i, 6)).to_ulong()];
    }

    while (encoded.length() % 4 != 0) {
        encoded += '=';
    }

    return encoded;
}

std::vector<char> embed_message(const std::vector<char>& data, const std::string& message, int offset) {
    std::string base64_message = base64_encode(message);
    std::cout << "Base64-encoded message: " << base64_message << std::endl;
    std::cout << "Base64 length (in characters): " << base64_message.length() << std::endl;

    std::string binary_message;
    for (char ch : base64_message) {
        binary_message += std::bitset<8>(ch).to_string();
    }

    std::string length_bits = std::bitset<32>(base64_message.length()).to_string();

    std::vector<char> modified_data = data;
    size_t i = 0;
    for (const char& bit : length_bits + binary_message) {
        modified_data[offset + i] = (modified_data[offset + i] & 0xFE) | (bit - '0');
        i++;
    }

    return modified_data;
}

int main() {
    std::string path = "/home/breezy/Documents/GitHub/Small-Projects/Thoth-Tech-Code-Files/steganography";
    std::string input_file_path = path + "/image.bmp";
    std::string output_file_path = path + "/encoded.bmp";
    
    std::ifstream input_file(input_file_path, std::ios::binary);
    std::vector<char> data((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    input_file.close();

    std::cout << "Enter the message to embed: ";
    std::string message_to_embed;
    std::getline(std::cin, message_to_embed);

    int pixel_data_offset = *reinterpret_cast<int*>(&data[10]);

    std::vector<char> encoded_data = embed_message(data, message_to_embed, pixel_data_offset);

    std::ofstream output_file(output_file_path, std::ios::binary);
    output_file.write(encoded_data.data(), encoded_data.size());
    output_file.close();

    std::cout << "Message embedded successfully in Base64! Encoded image saved as " << output_file_path << "." << std::endl;

    return 0;
}
