import os
path = "steganography/embed"

BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

def base64_encode(input_bytes):
    # Convert input bytes to binary representation
    binary_data = ''.join(format(byte, '08b') for byte in input_bytes)

    # Pad binary data to make its length a multiple of 6
    while len(binary_data) % 6 != 0:
        binary_data += '0'

    # Split binary data into 6-bit chunks and map to Base64 characters
    encoded = ''.join(BASE64_CHARS[int(binary_data[i:i+6], 2)] for i in range(0, len(binary_data), 6))

    # Add '=' padding if the original input length wasn't a multiple of 3
    while len(encoded) % 4 != 0:
        encoded += '='

    return encoded

def embed_file(data, file_path, offset):
    # Read the file to embed as binary data
    with open(file_path, "rb") as f:
        file_data = f.read()

    # Encode the file data using Base64
    base64_message = base64_encode(file_data)
    print(f"Base64-encoded file data length (in characters): {len(base64_message)}")

    binary_message = ''.join(format(ord(char), '08b') for char in base64_message)

    # Embed the length of the Base64 message (in characters) in the first 32 bits
    length_bits = format(len(base64_message), '032b')
    print(f"Length bits: {length_bits}")

    # Convert the bitmap to a mutable bytearray
    data = bytearray(data)

    # Embed the length bits
    for i, bit in enumerate(length_bits):
        data[offset + i] = (data[offset + i] & 0xFE) | int(bit)

    # Embed the Base64-encoded file data
    for i, bit in enumerate(binary_message):
        data[offset + 32 + i] = (data[offset + 32 + i] & 0xFE) | int(bit)

    return data

input_file_path = os.path.join(path, "image.bmp")
file_to_embed = os.path.join(path, "text.txt")  # File you want to embed
output_file_path = os.path.join(path, "encoded.bmp")

# Read the bitmap
with open(input_file_path, "rb") as f:
    data = f.read()

# Get the pixel data offset (e.g., 54 for standard BMP)
pixel_data_offset = int.from_bytes(data[10:14], byteorder='little')

# Embed the file
encoded_data = embed_file(data, file_to_embed, pixel_data_offset)

# Save the new bitmap
with open(output_file_path, "wb") as f:
    f.write(encoded_data)

print(f"File embedded successfully in Base64! Encoded image saved as {output_file_path}.")
