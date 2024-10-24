from splashkit import *

# Ensure the user enters a valid integer
def read_valid_integer(prompt):
    write(prompt)
    input_value = read_line()

    while not is_integer(input_value):
        write_line("Invalid integer input. Please enter a valid integer.")
        write(prompt)
        input_value = read_line()

    number = convert_to_integer(input_value)
    return number

# Ensure a valid operation is entered
def read_valid_operation():
    valid_operations = ['+', '-', '*', '^']
    operation = ''
    while operation not in valid_operations:
        write("Enter an operation (+, -, *, ^): ")
        input_op = read_line()
        operation = input_op[0]

        if operation not in valid_operations:
            write_line("Invalid operation. Please enter a valid operation (+, -, *, ^).")

    return operation

# Calculate the modular exponentiation of a number
def modular_exponentiation(base, exponent, mod):
    result = 1
    base = base % mod

    while exponent > 0:
        if exponent % 2 == 1:
            result = (result * base) % mod

        exponent = exponent >> 1
        base = (base * base) % mod

    return result

def main():
    # Collect the modulus, numbers, and operation from the user
    mod = read_valid_integer("Enter the modulus: ")
    a = read_valid_integer("Enter the first number: ")
    
    # Validate and read the operation
    operation = read_valid_operation()

    b = read_valid_integer("Enter the second number: ")

    result = 0

    if operation == '+':
        result = (a + b) % mod
    elif operation == '-':
        result = (a - b + mod) % mod
    elif operation == '*':
        result = (a * b) % mod
    elif operation == '^':
        result = modular_exponentiation(a, b, mod)

    write_line("Result: " + str(result))

if __name__ == "__main__":
    main()