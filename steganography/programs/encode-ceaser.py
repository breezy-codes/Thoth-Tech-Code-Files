import os

path = "/home/breezy/Documents/GitHub/Small-Projects/Thoth-Tech-Code-Files/steganography/programs/"

def ceaser_cipher_encode(input_string, shift):
    encoded_string = ""
    for character in input_string:
        if character.isalpha():
            base = ord('a') if character.islower() else ord('A')
            encoded_string += chr((ord(character) - base + shift) % 26 + base)
        else:
            encoded_string += character  # Non-alphabet characters remain unchanged
    return encoded_string

def base64_encode(input_string):
    BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
    encoded_string = ""
    value = 0
    bits = -6
    base64_mask = 0x3F

    for character in input_string.encode():
        value = (value << 8) + character
        bits += 8

        while bits >= 0:
            encoded_string += BASE64_CHARS[(value >> bits) & base64_mask]
            bits -= 6
    
    if bits > -6:
        encoded_string += BASE64_CHARS[((value << 8) >> (bits + 8)) & base64_mask]
    
    while len(encoded_string) % 4:
        encoded_string += "="
    
    return encoded_string

def embed_message(data, message, offset, shift):
    # Apply Caesar cipher shift to the message
    shifted_message = ceaser_cipher_encode(message, shift)
    print(f"Caesar cipher shifted message: {shifted_message}")

    # Encode the shifted message using Base64
    base64_message = base64_encode(shifted_message)
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

input_file_path = os.path.join(path, "cat.bmp")
output_file_path = os.path.join(path, "hiddencat.bmp")
with open(input_file_path, "rb") as f:
    data = f.read()

print("Enter the message to embed: ")
message_to_embed = input()

print("Enter the Caesar cipher shift value: ")
shift_value = int(input())

# Specify the offset where the pixel data starts (e.g., 54 for standard BMP)
pixel_data_offset = int.from_bytes(data[10:14], byteorder='little')

encoded_data = embed_message(data, message_to_embed, pixel_data_offset, shift_value)
with open(output_file_path, "wb") as f:
    f.write(encoded_data)
print(f"Message embedded successfully in Base64! Encoded image saved as {output_file_path}.")
