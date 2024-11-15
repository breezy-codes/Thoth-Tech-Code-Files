import base64

def embed_message(data, message, offset):
    # Encode the message in Base64
    base64_message = base64.b64encode(message.encode('utf-8')).decode('utf-8')
    binary_message = ''.join(format(ord(char), '08b') for char in base64_message)

    # Embed the length of the Base64 message (in bytes) in the first 32 bits
    length_bits = format(len(base64_message), '032b')
    data = bytearray(data)

    for i, bit in enumerate(length_bits + binary_message):
        # Change the LSB of each pixel’s byte to match the message bit
        data[offset + i] = (data[offset + i] & 0xFE) | int(bit)

    return data

# Path to the original BMP file
input_file_path = "/home/breezy/Documents/GitHub/Small-Projects/Thoth-Tech-Code-Files/image.bmp"
output_file_path = "encoded_image_base64_with_length.bmp"

# Read the original BMP file
with open(input_file_path, "rb") as f:
    data = f.read()

# Define the message you want to embed
message_to_embed = input("Enter the message to embed: ")

# Specify the offset where the pixel data starts (e.g., 54 for standard BMP)
pixel_data_offset = int.from_bytes(data[10:14], byteorder='little')

# Embed the message into the BMP file
encoded_data = embed_message(data, message_to_embed, pixel_data_offset)

# Save the modified BMP file with the encoded message
with open(output_file_path, "wb") as f:
    f.write(encoded_data)

print(f"Message embedded successfully in Base64! Encoded image saved as {output_file_path}.")
