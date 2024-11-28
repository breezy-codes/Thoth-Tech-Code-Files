from splashkit import *

def caesar_cipher_encrypt(plaintext, shift):
    ciphertext = ""
    for c in plaintext:
        if c.isalpha():
            if c.islower():
                ciphertext += chr((ord(c) - ord('a') + shift) % 26 + ord('a'))
            else:
                ciphertext += chr((ord(c) - ord('A') + shift) % 26 + ord('A'))
        else:
            ciphertext += c
    return ciphertext

def caesar_cipher_decode(ciphertext, shift):
    return caesar_cipher_encrypt(ciphertext, -shift)

def caesar_cipher_brute_force(input_string):
    for shift in range(26):
        write_line(f"Shift {shift} => {caesar_cipher_decode(input_string, shift)}")


write_line("Enter the encrypted message: ")
ciphertext = read_line()

caesar_cipher_brute_force(cphertext)