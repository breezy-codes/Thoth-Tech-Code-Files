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

# Calculate the greatest common divisor of two numbers
def gcd(a, b):
    while b != 0:
        temp = b
        b = a % b
        a = temp
    return a

# Calculate the least common multiple of two numbers
def lcm(a, b):
    return abs(a * b) // gcd(a, b)

def main():
    # Collect two valid integers from the user
    num1 = read_valid_integer("Enter the first integer: ")
    num2 = read_valid_integer("Enter the second integer: ")

    # Calculate the LCM of the two numbers
    result = lcm(num1, num2)
    write_line("The LCM of " + str(num1) + " and " + str(num2) + " is " + str(result))

if __name__ == "__main__":
    main()
