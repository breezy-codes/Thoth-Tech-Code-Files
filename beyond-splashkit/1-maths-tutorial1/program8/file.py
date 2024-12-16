from splashkit import *

MAX_ROWS = 10
MAX_COLS = 10

# Ensure the user enters a valid integer
def read_valid_integer(prompt):
    write(prompt)
    input_value = read_line()

    while not is_integer(input_value):
        write_line("Invalid input. Please enter a valid integer.")
        write(prompt)
        input_value = read_line()

    return convert_to_integer(input_value)

# Parse and extract numbers from matrix input
def parse_numbers(input_str, numbers, max_numbers):
    num_str = ""
    count = 0

    for c in input_str:
        if c in ['[', ']', ',']:  # Ignore brackets and commas
            if num_str and is_integer(num_str):  # Check if we have a valid integer
                numbers[count] = convert_to_integer(num_str)
                count += 1
                num_str = ""
        else:
            num_str += c

    if num_str and is_integer(num_str):  # Check the last number
        numbers[count] = convert_to_integer(num_str)
        count += 1

    return count

# Read matrix elements from user
def read_matrix(mat, rows, cols):
    numbers = [0] * (MAX_ROWS * MAX_COLS)
    count = 0

    while count != rows * cols:
        write("Enter the matrix elements (e.g. [2,3],[4,4]): ")
        input_str = read_line()
        count = parse_numbers(input_str, numbers, MAX_ROWS * MAX_COLS)

        if count != rows * cols:
            write_line(f"Incorrect number of elements. Expected {rows * cols} elements.")

    idx = 0
    for i in range(rows):
        for j in range(cols):
            mat[i][j] = numbers[idx]
            idx += 1

# Print the matrix
def print_matrix(mat, rows, cols):
    for i in range(rows):
        for j in range(cols):
            write(f"{mat[i][j]}\t")
        write_line("")

# Perform matrix addition or subtraction
def matrix_operation(a, b, result, rows, cols, op):
    for i in range(rows):
        for j in range(cols):
            if op == '+':
                result[i][j] = a[i][j] + b[i][j]
            elif op == '-':
                result[i][j] = a[i][j] - b[i][j]

# Perform matrix multiplication
def multiply_matrices(a, b, result, rows_a, cols_a, cols_b):
    for i in range(rows_a):
        for j in range(cols_b):
            result[i][j] = 0
            for k in range(cols_a):
                result[i][j] += a[i][k] * b[k][j]

# Ensure a valid matrix operation is entered
def read_valid_operation():
    operation = ''
    while operation not in ['+', '-', '*']:
        write("Enter operation (+, -, *): ")
        input_str = read_line()
        operation = input_str[0]
    return operation

def main():
    mat1 = [[0] * MAX_COLS for _ in range(MAX_ROWS)]
    mat2 = [[0] * MAX_COLS for _ in range(MAX_ROWS)]
    result = [[0] * MAX_COLS for _ in range(MAX_ROWS)]
    
    # First matrix input
    rows1 = read_valid_integer("Enter number of rows for the first matrix: ")
    cols1 = read_valid_integer("Enter number of columns for the first matrix: ")
    read_matrix(mat1, rows1, cols1)

    # Second matrix input
    rows2 = read_valid_integer("Enter number of rows for the second matrix: ")
    cols2 = read_valid_integer("Enter number of columns for the second matrix: ")
    read_matrix(mat2, rows2, cols2)

    operation = read_valid_operation()

    # Perform matrix operation
    if operation == '+':
        if rows1 == rows2 and cols1 == cols2:
            matrix_operation(mat1, mat2, result, rows1, cols1, '+')
            write_line("Result of addition:")
            print_matrix(result, rows1, cols1)
        else:
            write_line("Matrices must have the same dimensions for addition.")
    elif operation == '-':
        if rows1 == rows2 and cols1 == cols2:
            matrix_operation(mat1, mat2, result, rows1, cols1, '-')
            write_line("Result of subtraction:")
            print_matrix(result, rows1, cols1)
        else:
            write_line("Matrices must have the same dimensions for subtraction.")
    elif operation == '*':
        if cols1 == rows2:
            multiply_matrices(mat1, mat2, result, rows1, cols1, cols2)
            write_line("Result of multiplication:")
            print_matrix(result, rows1, cols2)
        else:
            write_line("Number of columns of the first matrix must equal the number of rows of the second matrix for multiplication.")

if __name__ == "__main__":
    main()
