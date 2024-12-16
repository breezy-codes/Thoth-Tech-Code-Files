def embed_message(data, message, offset):
    binary_message = ''.join(format(ord(char), '08b') for char in message)
    data = bytearray(data)
    # Embed the length of the message in the first 32 bits
    for i, bit in enumerate(binary_message):
        data[offset + i] = (data[offset + i] & 0xFE) | int(bit)
    return data


input_file_path = "/home/breezy/Documents/GitHub/Small-Projects/Thoth-Tech-Code-Files/image.bmp"
output_file_path = "encoded_image.bmp"

with open(input_file_path, "rb") as f: data = f.read()


message_to_embed = input("Enter the message to embed: ")

# Specify the offset where the pixel data starts (e.g., 54 for standard BMP)
pixel_data_offset = int.from_bytes(data[10:14], byteorder='little')

# Embed the message into the BMP file
encoded_data = embed_message(data, message_to_embed, pixel_data_offset)


with open(output_file_path, "wb") as f: f.write(encoded_data)
print(f"Message embedded successfully! Encoded image saved as {output_file_path}.")
