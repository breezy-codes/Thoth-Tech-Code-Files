#include "splashkit.h"

const int MAX_ROWS = 10;  
const int MAX_COLS = 10;

// Ensure the user enters a valid integer
int read_valid_integer(const string &prompt)
{
    int number;
    write(prompt);
    string input = read_line();

    while (!is_integer(input))
    {
        write_line("Invalid input. Please enter a valid integer.");
        write(prompt);
        input = read_line();
    }

    return convert_to_integer(input);
}

// Parse and extract numbers from matrix input
void parse_numbers(const string& input, int numbers[], int max_numbers, int& count)
{
    string num_str = "";
    count = 0;

    for (char c : input)
    {
        if (c == '[' || c == ']' || c == ',') // Ignore brackets and commas
        {
            if (!num_str.empty() && is_integer(num_str)) // Check if we have a valid integer
            {
                numbers[count++] = convert_to_integer(num_str);
                num_str = "";
            }
        }
        else
        {
            num_str += c;
        }
    }

    if (!num_str.empty() && is_integer(num_str)) // Check the last number
    {
        numbers[count++] = convert_to_integer(num_str);
    }
}

// Read matrix elements from user
void read_matrix(int mat[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    string input;
    int numbers[MAX_ROWS * MAX_COLS];
    int count;

    do
    {
        write("Enter the matrix elements (e.g. [2,3],[4,4]): ");
        input = read_line();
        parse_numbers(input, numbers, MAX_ROWS * MAX_COLS, count);

        if (count != rows * cols)
            write_line("Incorrect number of elements. Expected " + std::to_string(rows * cols) + " elements.");
    } while (count != rows * cols);

    int idx = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat[i][j] = numbers[idx++];
}

// Print the matrix
void print_matrix(const int mat[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            write(std::to_string(mat[i][j]) + "\t");
        }
        write_line("");
    }
}

// Perform matrix addition or subtraction
void matrix_operation(const int a[MAX_ROWS][MAX_COLS], const int b[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols, char op)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            if (op == '+') result[i][j] = a[i][j] + b[i][j];
            if (op == '-') result[i][j] = a[i][j] - b[i][j];
        }
}

// Perform matrix multiplication
void multiply_matrices(const int a[MAX_ROWS][MAX_COLS], const int b[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows_a, int cols_a, int cols_b)
{
    for (int i = 0; i < rows_a; i++)
        for (int j = 0; j < cols_b; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols_a; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
}

// Ensure a valid matrix operation is entered
char read_valid_operation()
{
    char operation;
    string input;

    do
    {
        write("Enter operation (+, -, *): ");
        input = read_line();
        operation = input[0];
    } while (operation != '+' && operation != '-' && operation != '*');

    return operation;
}

int main()
{
    int mat1[MAX_ROWS][MAX_COLS], mat2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int rows1, cols1, rows2, cols2;

    write_line("Matrix Operation Program");

    // First matrix input
    rows1 = read_valid_integer("Enter number of rows for the first matrix: ");
    cols1 = read_valid_integer("Enter number of columns for the first matrix: ");
    read_matrix(mat1, rows1, cols1);

    // Second matrix input
    rows2 = read_valid_integer("Enter number of rows for the second matrix: ");
    cols2 = read_valid_integer("Enter number of columns for the second matrix: ");
    read_matrix(mat2, rows2, cols2);

    char operation = read_valid_operation();

    // Perform matrix operation
    if (operation == '+')
    {
        if (rows1 == rows2 && cols1 == cols2)
        {
            matrix_operation(mat1, mat2, result, rows1, cols1, '+');
            write_line("Result of addition:");
            print_matrix(result, rows1, cols1);
        }
        else
            write_line("Matrices must have the same dimensions for addition.");
    }
    else if (operation == '-')
    {
        if (rows1 == rows2 && cols1 == cols2)
        {
            matrix_operation(mat1, mat2, result, rows1, cols1, '-');
            write_line("Result of subtraction:");
            print_matrix(result, rows1, cols1);
        }
        else
            write_line("Matrices must have the same dimensions for subtraction.");
    }
    else if (operation == '*')
    {
        if (cols1 == rows2)
        {
            multiply_matrices(mat1, mat2, result, rows1, cols1, cols2);
            write_line("Result of multiplication:");
            print_matrix(result, rows1, cols2);
        }
        else
            write_line("Number of columns of the first matrix must equal the number of rows of the second matrix for multiplication.");
    }

    return 0;
}