import base64

def extract_message(data, offset):
    # Extract the length of the Base64 message (first 32 bits)
    length_bits = ''.join(str(data[offset + i] & 1) for i in range(32))
    base64_length = int(length_bits, 2)

    # Extract the Base64 message
    binary_message = ''.join(str(data[offset + 32 + i] & 1) for i in range(base64_length * 8))
    base64_message = ''.join(chr(int(binary_message[i:i+8], 2)) for i in range(0, len(binary_message), 8))

    # Decode the Base64 message back to the original message
    return base64.b64decode(base64_message).decode('utf-8')

# Path to the encoded BMP file
encoded_file_path = "encoded_image_base64_with_length.bmp"

# Read the encoded BMP file
with open(encoded_file_path, "rb") as f:
    data = f.read()

# Specify the offset where the pixel data starts (e.g., 54 for standard BMP)
pixel_data_offset = int.from_bytes(data[10:14], byteorder='little')

# Extract the message from the BMP file
hidden_message = extract_message(data, pixel_data_offset)

print(f"Extracted message: {hidden_message}")
