import os
path = "steganography/encode"

BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

def base64_decode(encoded_string):
    # Remove '=' padding
    encoded_string = encoded_string.rstrip('=')

    # Convert Base64 characters to binary
    binary_data = ''.join(format(BASE64_CHARS.index(char), '06b') for char in encoded_string)

    # Group binary into 8-bit chunks and convert to characters
    decoded = ''.join(chr(int(binary_data[i:i+8], 2)) for i in range(0, len(binary_data), 8))

    return decoded

def extract_message(data, offset):
    # Extract the length of the Base64 message (first 32 bits)
    length_bits = ''.join(str(data[offset + i] & 1) for i in range(32))
    print(f"Length bits: {length_bits}")
    base64_length = int(length_bits, 2)
    print(f"Extracted Base64 length (in characters): {base64_length}")

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
print(f"Extracted message: {hidden_message}")
