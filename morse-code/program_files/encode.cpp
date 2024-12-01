#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<char, string> MORSE_CODE_DICT = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
    {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
    {'0', "-----"}, {',', "--..--"}, {'.', ".-.-.-"}, {'?', "..--.."},
    {'\'', ".----."}, {'!', "-.-.--"}, {'/', "-..-."}, {'(', "-.--."},
    {')', "-.--.-"}, {'&', ".-..."}, {':', "---..."}, {';', "-.-.-."},
    {'=', "-...-"}, {'+', ".-.-."}, {'-', "-....-"}, {'_', "..--.-"},
    {'"', ".-..-."}, {'$', "...-..-"}, {'@', ".--.-."}, {' ', "/"}
};

string encode_to_morse(const string &text) {
    ostringstream encoded_message;
    for (char c : text) {
        char upper_c = toupper(c);
        if (MORSE_CODE_DICT.find(upper_c) != MORSE_CODE_DICT.end()) {
            encoded_message << MORSE_CODE_DICT[upper_c] << ' ';
        } else {
            encoded_message << "? ";
        }
    }
    string result = encoded_message.str();
    if (!result.empty()) {
        result.pop_back();  // Remove the trailing space
    }
    return result;
}

int main() {
    string text;
    cout << "Enter the text to encode using morse code:" << endl;
    getline(cin, text);
    string encoded_text = encode_to_morse(text);
    cout << "Each Morse code character is separated by a space, and each word is separated by a /" << endl;
    cout << "The Morse code for '" << text << "' is:" << endl;
    cout << encoded_text << endl;
    return 0;
}