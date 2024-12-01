# Morse Code Dictionary
MORSE_CODE_DICT = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 
    'F': '..-.', 'G': '--.', 'H': '....', 'I': '..', 'J': '.---',
    'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---',
    'P': '.--.', 'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-',
    'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--',
    'Z': '--..', '1': '.----', '2': '..---', '3': '...--', '4': '....-', 
    '5': '.....', '6': '-....', '7': '--...', '8': '---..', '9': '----.', 
    '0': '-----', ',': '--..--', '.': '.-.-.-', '?': '..--..', 
    "'": '.----.', '!': '-.-.--', '/': '-..-.', '(': '-.--.', 
    ')': '-.--.-', '&': '.-...', ':': '---...', ';': '-.-.-.', 
    '=': '-...-', '+': '.-.-.', '-': '-....-', '_': '..--.-', 
    '"': '.-..-.', '$': '...-..-', '@': '.--.-.', ' ': '/'
}

# Function to decode Morse code to text
def decode_from_morse(morse_code):
    reversed_dict = {v: k for k, v in MORSE_CODE_DICT.items()}
    decoded_message = []
    for code in morse_code.split(' '):
        if code in reversed_dict:
            decoded_message.append(reversed_dict[code])
        elif code == '/':  # Morse code for space
            decoded_message.append(' ')
        else:
            decoded_message.append('?')  # Unknown Morse code
    return ''.join(decoded_message)

print("Enter the Morse code to decode:")
text = input()
decoded_text = decode_from_morse(text)
print("Each Morse code character is separated by a space, and each word is separated by a /")
print(f"The decoded text for '{text}' is:")