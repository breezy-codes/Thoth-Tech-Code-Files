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

def main():
    # Get the limit up to which we want to find primes    
    limit = read_valid_integer("Find all prime numbers up to: ")

    # Find all primes up to the limit
    write_line("Prime numbers up to " + str(limit) + ":")
    for i in range(2, limit + 1):
        if is_prime(i):
            write(str(i) + " ")

    write_line("")  # Print a new line at the end

if __name__ == "__main__":
    main()
