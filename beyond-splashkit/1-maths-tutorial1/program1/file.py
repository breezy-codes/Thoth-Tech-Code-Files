from splashkit import *

# Calculate the square root of a number
def sqrt(n):
    if n == 0 or n == 1:
        return n

    estimate = n
    precision = 0.00001

    while (estimate - n / estimate) > precision:
        estimate = (estimate + n / estimate) / 2.0

    return estimate

# Check if a number is prime
def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

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

# Main function
def main():
    number = read_valid_integer("Enter an integer: ")

    if is_prime(number):
        write_line(f"{number} is a prime number.")
    else:
        write_line(f"{number} is not a prime number.")

if __name__ == "__main__":
    main()
