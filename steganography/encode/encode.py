import os
path = "steganography/encode"

BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

def base64_encode(input_string):
    binary_data = ''.join(format(ord(char), '08b') for char in input_string)

    # Pad binary data to make its length a multiple of 6
    while len(binary_data) % 6 != 0:
        binary_data += '0'

    # Split binary data into 6-bit chunks and map to Base64 characters
    encoded = ''.join(BASE64_CHARS[int(binary_data[i:i+6], 2)] for i in range(0, len(binary_data), 6))

    # Add '=' padding if the original input length wasn't a multiple of 3
    while len(encoded) % 4 != 0:
        encoded += '='

    return encoded

def embed_message(data, message, offset):
    # Encode the message using Base64
    base64_message = base64_encode(message)
    print(f"Base64-encoded message: {base64_message}")
    print(f"Base64 length (in characters): {len(base64_message)}")

    binary_message = ''.join(format(ord(char), '08b') for char in base64_message)

    # Embed the length of the Base64 message (in bytes) in the first 32 bits
    length_bits = format(len(base64_message), '032b')
    print(f"Length bits: {length_bits}")

    data = bytearray(data)
    for i, bit in enumerate(length_bits + binary_message):
        data[offset + i] = (data[offset + i] & 0xFE) | int(bit)

    return data

input_file_path = os.path.join(path, "image.bmp")
output_file_path = os.path.join(path, "encoded.bmp")
with open(input_file_path, "rb") as f:data = f.read()

message_to_embed = input("Enter the message to embed: ")

# Specify the offset where the pixel data starts (e.g., 54 for standard BMP)
pixel_data_offset = int.from_bytes(data[10:14], byteorder='little')

encoded_data = embed_message(data, message_to_embed, pixel_data_offset)
with open(output_file_path, "wb") as f: f.write(encoded_data)
print(f"Message embedded successfully in Base64! Encoded image saved as {output_file_path}.")
