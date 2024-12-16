def extract_message(data, offset, length):
    # Extract the message bits from the LSB of each byte
    binary_message = ''.join(str(data[offset + i] & 1) for i in range(length * 8))
    message = ''.join(chr(int(binary_message[i:i+8], 2)) for i in range(0, len(binary_message), 8))
    return message

encoded_file_path = "encoded_image.bmp"
with open(encoded_file_path, "rb") as f: data = f.read()

# Specify the offset where the pixel data starts (e.g., 54 for standard BMP)
pixel_data_offset = int.from_bytes(data[10:14], byteorder='little')

# Define the length of the message to extract
message_length = int(input("Enter the length of the hidden message: "))
hidden_message = extract_message(data, pixel_data_offset, message_length)

print(f"Extracted message: {hidden_message}")
