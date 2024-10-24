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

# Ensure the user enters a valid double
def read_valid_double(prompt):
    write(prompt)
    input_value = read_line()

    while not is_double(input_value):
        write_line("Invalid input. Please enter a valid number.")
        write(prompt)
        input_value = read_line()

    number = convert_to_double(input_value)
    return number

def main():
    # Input coefficients with validation
    a = read_valid_double("Enter coefficient a: ")
    b = read_valid_double("Enter coefficient b: ")
    c = read_valid_double("Enter coefficient c: ")

    # Calculate the discriminant of the quadratic equation
    discriminant = b * b - 4 * a * c

    # Check if 'a' is zero, which would not be a quadratic equation
    if a == 0:
        write_line("Coefficient a cannot be zero.")
    elif discriminant > 0:
        # Two real roots
        x1 = (-b + sqrt(discriminant)) / (2 * a)
        x2 = (-b - sqrt(discriminant)) / (2 * a)
        write_line("Real roots:")
        write_line("x1 = " + str(x1))
        write_line("x2 = " + str(x2))
    elif discriminant == 0:
        # One real root
        x = -b / (2 * a)
        write_line("One real root:")
        write_line("x = " + str(x))
    else:
        # Complex roots
        real_part = -b / (2 * a)
        imaginary_part = sqrt(-discriminant) / (2 * a)
        write_line("Complex roots:")
        write_line("x1 = " + str(real_part) + " + " + str(imaginary_part) + "i")
        write_line("x2 = " + str(real_part) + " - " + str(imaginary_part) + "i")

if __name__ == "__main__":
    main()
