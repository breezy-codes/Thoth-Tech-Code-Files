from splashkit import *

MAX_DEGREE = 100  # Define a maximum degree for polynomials

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

# Read a polynomial from the user
def read_polynomial(poly, degree):
    degree[0] = read_valid_integer("Enter the degree of the polynomial: ")

    for i in range(degree[0], -1, -1):
        poly[i] = read_valid_integer("Enter coefficient for x^" + str(i) + ": ")

    # Initialise unused coefficients to 0
    for i in range(degree[0] + 1, MAX_DEGREE + 1):
        poly[i] = 0

# Print a polynomial to the console
def print_polynomial(poly, degree):
    for i in range(degree, -1, -1):
        if poly[i] != 0:
            if i != degree and poly[i] > 0:
                write("+")
            if i == 0 or poly[i] != 1:
                write(str(poly[i]))
            if i > 0:
                write("x")
            if i > 1:
                write("^" + str(i))
            write(" ")

# Add two polynomials together
def add_polynomials(a, a_degree, b, b_degree, result, result_degree):
    result_degree[0] = max(a_degree, b_degree)

    for i in range(result_degree[0] + 1):
        coef_a = a[i] if i <= a_degree else 0
        coef_b = b[i] if i <= b_degree else 0
        result[i] = coef_a + coef_b

    # Initialise unused coefficients in result array to 0
    for i in range(result_degree[0] + 1, MAX_DEGREE + 1):
        result[i] = 0

# Multiply two polynomials together
def multiply_polynomials(a, a_degree, b, b_degree, result, result_degree):
    result_degree[0] = a_degree + b_degree

    # Initialise result array to 0
    for i in range(result_degree[0] + 1):
        result[i] = 0

    for i in range(a_degree + 1):
        for j in range(b_degree + 1):
            result[i + j] += a[i] * b[j]

    # Initialise unused coefficients in result array to 0
    for i in range(result_degree[0] + 1, MAX_DEGREE + 1):
        result[i] = 0

def main():
    poly1 = [0] * (MAX_DEGREE + 1)  # Array for first polynomial
    poly2 = [0] * (MAX_DEGREE + 1)  # Array for second polynomial
    result = [0] * (MAX_DEGREE * 2 + 1)  # Result array (max possible degree = MAX_DEGREE * 2)
    degree1 = [0]
    degree2 = [0]
    result_degree = [0]

    write_line("Enter the first polynomial:")
    read_polynomial(poly1, degree1)

    write_line("Enter the second polynomial:")
    read_polynomial(poly2, degree2)

    write("Enter operation (+ or *): ")
    input_op = read_line()
    operation = input_op[0]

    # Print the polynomials to show what is being added or multiplied
    write("First polynomial: ")
    print_polynomial(poly1, degree1[0])

    write("Second polynomial: ")
    print_polynomial(poly2, degree2[0])

    if operation == '+':
        add_polynomials(poly1, degree1[0], poly2, degree2[0], result, result_degree)
        write_line("Result of addition:")
    elif operation == '*':
        multiply_polynomials(poly1, degree1[0], poly2, degree2[0], result, result_degree)
        write_line("Result of multiplication:")
    else:
        write_line("Invalid operation.")
        return

    # Print the result polynomial
    print_polynomial(result, result_degree[0])

if __name__ == "__main__":
    main()
