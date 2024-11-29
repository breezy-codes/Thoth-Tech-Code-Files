from splashkit import *

def from_hex(hex):
    if '0' <= hex <= '9':
        return ord(hex) - ord('0')
    if 'A' <= hex <= 'F':
        return ord(hex) - ord('A') + 10
    if 'a' <= hex <= 'f':
        return ord(hex) - ord('a') + 10
    return -1  # Invalid hex character

def url_decode(input_string):
    decoded_string = ""
    i = 0
    while i < len(input_string):
        if input_string[i] == '%':
            if i + 2 < len(input_string):
                hex1 = input_string[i + 1]
                hex2 = input_string[i + 2]
                decoded_char = (from_hex(hex1) << 4) | from_hex(hex2)
                if decoded_char >= 0:
                    decoded_string += chr(decoded_char)
                    i += 2
                else:
                    decoded_string += '%'
            else:
                decoded_string += '%'
        elif input_string[i] == '+':
            decoded_string += ' '
        else:
            decoded_string += input_string[i]
        i += 1
    return decoded_string

def main():
    input_string = "https%3A%2F%2Fwww.example.com%2Fsearch%3Fq%3Dhello%20world"
    print(url_decode(input_string))
    
main()