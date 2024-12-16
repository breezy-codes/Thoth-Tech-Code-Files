BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

def is_binary(binary_string):
    return all(character in '01' for character in binary_string) and bool(binary_string)

def is_hex(hex_string):
    return all(character in '0123456789ABCDEFabcdef' for character in hex_string) and bool(hex_string)

def is_octal(octal_string):
    return all(character in '01234567' for character in octal_string) and bool(octal_string)

def dec_to_bin(decimal_value):
    if decimal_value == 0:
        return "0"
    
    binary_string = ""
    while decimal_value > 0:
        binary_string = ("1" if decimal_value & 1 else "0") + binary_string
        decimal_value >>= 1
    return binary_string

def bin_to_dec(binary_string):
    if not is_binary(binary_string):
        return 0

    decimal_value = 0
    for i, character in enumerate(reversed(binary_string)):
        if character == '1':
            decimal_value += (1 << i)
    return decimal_value

def hex_to_bin(hex_string):
    if not is_hex(hex_string):
        return ""
    
    binary_string = ""
    for hex_character in hex_string:
        hex_value = int(hex_character, 16)
        for i in range(3, -1, -1):
            binary_string += "1" if (hex_value >> i) & 1 else "0"
    
    if len(hex_string) == 1:
        first_one = binary_string.find('1')
        return "0" if first_one == -1 else binary_string[first_one:]
    
    return binary_string

def bin_to_hex(binary_string):
    if not is_binary(binary_string):
        return ""
    
    length = len(binary_string)
    padding = (4 - (length % 4)) % 4
    padded_binary_string = "0" * padding + binary_string
    
    hex_string = ""
    for i in range(0, len(padded_binary_string), 4):
        hex_value = int(padded_binary_string[i:i+4], 2)
        hex_string += hex(hex_value)[2:].upper()
    return hex_string

def dec_to_oct(decimal_value):
    if decimal_value == 0:
        return "0"
    
    octal_string = ""
    while decimal_value > 0:
        octal_string = str(decimal_value % 8) + octal_string
        decimal_value //= 8
    return octal_string

def oct_to_dec(octal_string):
    if not is_octal(octal_string):
        return 0

    decimal_value = 0
    for i, character in enumerate(reversed(octal_string)):
        decimal_value += int(character) * (8 ** i)
    return decimal_value

def oct_to_bin(octal_string):
    if not is_octal(octal_string):
        return ""
    
    binary_string = ""
    for octal_character in octal_string:
        octal_value = int(octal_character)
        for i in range(2, -1, -1):
            binary_string += "1" if (octal_value >> i) & 1 else "0"
    
    first_one = binary_string.find('1')
    return "0" if first_one == -1 else binary_string[first_one:]

def bin_to_oct(binary_string):
    if not is_binary(binary_string):
        return ""
    
    padding = (3 - (len(binary_string) % 3)) % 3
    padded_binary_string = "0" * padding + binary_string
    
    octal_string = ""
    for i in range(0, len(padded_binary_string), 3):
        octal_value = int(padded_binary_string[i:i+3], 2)
        octal_string += str(octal_value)
    
    first_non_zero = octal_string.find('1')
    return "0" if first_non_zero == -1 else octal_string[first_non_zero:]

def hex_to_oct(hex_string):
    if not is_hex(hex_string):
        return ""
    
    binary_string = hex_to_bin(hex_string)
    return bin_to_oct(binary_string)

def oct_to_hex(octal_string):
    if not is_octal(octal_string):
        return ""
    
    binary_string = oct_to_bin(octal_string)
    return bin_to_hex(binary_string)

def base64_encode(input_string):
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

def main():
    # Test binary functions
    print("Testing Binary Functions:")
    bin = "1010"
    print("Binary to Decimal (" + bin + "): " + str(bin_to_dec(bin)))
    dec = 10
    print("Decimal to Binary (" + str(dec) + "): " + dec_to_bin(dec))

    # Test hexadecimal functions
    print("\nTesting Hexadecimal Functions:")
    hex = "A"
    print("Hex to Binary (" + hex + "): " + hex_to_bin(hex))
    bin_from_hex = "1010"
    print("Binary to Hex (" + bin_from_hex + "): " + bin_to_hex(bin_from_hex))

    # Test octal functions
    print("\nTesting Octal Functions:")
    oct = "12"
    print("Octal to Decimal (" + oct + "): " + str(oct_to_dec(oct)))
    print("Decimal to Octal (" + str(dec) + "): " + dec_to_oct(dec))
    print("Octal to Binary (" + oct + "): " + oct_to_bin(oct))
    print("Binary to Octal (" + bin + "): " + bin_to_oct(bin))
    print("Hex to Octal (" + hex + "): " + hex_to_oct(hex))
    print("Octal to Hex (" + oct + "): " + oct_to_hex(oct))

    # Test Base64 functions
    print("\nTesting Base64 Functions:")
    plain_text = "Hello"
    encoded = base64_encode(plain_text)
    print("Base64 Encode (" + plain_text + "): " + encoded)
    decoded = base64_decode(encoded)
    print("Base64 Decode (" + encoded + "): " + decoded)

    # Validation functions
    print("\nTesting Validation Functions:")
    print("Is Binary (" + bin + "): " + ("True" if is_binary(bin) else "False"))
    print("Is Hex (" + hex + "): " + ("True" if is_hex(hex) else "False"))
    print("Is Octal (" + oct + "): " + ("True" if is_octal(oct) else "False"))

if __name__ == "__main__":
    main()