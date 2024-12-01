#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<string, char> morse_code_dict = {
    {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'}, 
    {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'},
    {"-.-", 'K'}, {".-..", 'L'}, {"--", 'M'}, {"-.", 'N'}, {"---", 'O'},
    {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
    {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'}, {"-.--", 'Y'},
    {"--..", 'Z'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'}, 
    {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'}, 
    {"-----", '0'}, {"--..--", ','}, {".-.-.-", '.'}, {"..--..", '?'}, 
    {".----.", '\''}, {"-.-.--", '!'}, {"-..-.", '/'}, {"-.--.", '('}, 
    {"-.--.-", ')'}, {".-...", '&'}, {"---...", ':'}, {"-.-.-.", ';'}, 
    {"-...-", '='}, {".-.-.", '+'}, {"-....-", '-'}, {"..--.-", '_'}, 
    {".-..-.", '"'}, {"...-..-", '$'}, {".--.-.", '@'}, {"/", ' '}
};

string decode_from_morse(const string& morse_code) {
    istringstream iss(morse_code);
    string code;
    string decoded_message;
    while (iss >> code) {
        if (morse_code_dict.find(code) != morse_code_dict.end()) {
            decoded_message += morse_code_dict[code];
        } else {
            decoded_message += '?';  // Unknown Morse code
        }
    }
    return decoded_message;
}

int main() {
    string text;
    cout << "Enter the Morse code to decode:" << endl;
    getline(cin, text);
    string decoded_text = decode_from_morse(text);
    cout << "Each Morse code character is separated by a space, and each word is separated by a /" << endl;
    cout << "The decoded text for '" << text << "' is: " << decoded_text << endl;
    return 0;
}