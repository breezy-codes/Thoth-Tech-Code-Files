from splashkit import *
import os
path = "/home/breezy/Documents/GitHub/Small-Projects/Thoth-Tech-Code-Files/steganography"

BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

def base64_decode(input_string):
    decoded_string = bytearray()
    value = 0
    bits = -8

    for character in input_string:
        if character not in BASE64_CHARS:
            if character == "=":
                break
            continue
        
        value = (value << 6) + BASE64_CHARS.index(character)
        bits += 6

        if bits >= 0:
            decoded_string.append((value >> bits) & 0xFF)
            bits -= 8
    
    return decoded_string.decode()

def extract_message(data, offset):
    # Extract the length of the Base64 message (first 32 bits)
    length_bits = ''.join(str(data[offset + i] & 1) for i in range(32))
    write_line(f"Length bits: {length_bits}")
    base64_length = int(length_bits, 2)
    write_line(f"Extracted Base64 length (in characters): {base64_length}")

    # Extract the Base64 message
    binary_message = ''.join(str(data[offset + 32 + i] & 1) for i in range(base64_length * 8))
    base64_message = ''.join(chr(int(binary_message[i:i+8], 2)) for i in range(0, len(binary_message), 8))

    # Decode the Base64 message
    return base64_decode(base64_message)

encoded_file_path = os.path.join(path, "encoded.bmp")
with open(encoded_file_path, "rb") as f: data = f.read()

# Specify the offset where the pixel data starts (e.g., 54 for standard BMP)
pixel_data_offset = int.from_bytes(data[10:14], byteorder='little')

hidden_message = extract_message(data, pixel_data_offset)
write_line(f"Extracted message: {hidden_message}")
