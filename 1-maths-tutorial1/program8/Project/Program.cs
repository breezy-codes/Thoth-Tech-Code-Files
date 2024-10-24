using SplashKitSDK;
using static SplashKitSDK.SplashKit;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

// Ensure the user enters a valid integer
int ReadValidInteger(string prompt)
{
    Write(prompt);
    string input = ReadLine();

    while (!IsInteger(input))
    {
        WriteLine("Invalid input. Please enter a valid integer.");
        Write(prompt);
        input = ReadLine();
    }

    return ConvertToInteger(input);
}

// Parse and extract numbers from matrix input
void ParseNumbers(string input, int[] numbers, int maxNumbers, out int count)
{
    string numStr = "";
    count = 0;

    foreach (char c in input)
    {
        if (c == '[' || c == ']' || c == ',') // Ignore brackets and commas
        {
            if (!string.IsNullOrEmpty(numStr) && IsInteger(numStr)) // Check if we have a valid integer
            {
                numbers[count++] = ConvertToInteger(numStr);
                numStr = "";
            }
        }
        else
        {
            numStr += c;
        }
    }

    if (!string.IsNullOrEmpty(numStr) && IsInteger(numStr)) // Check the last number
    {
        numbers[count++] = ConvertToInteger(numStr);
    }
}

// Read matrix elements from user
void ReadMatrix(int[,] mat, int rows, int cols)
{
    string input;
    int[] numbers = new int[MAX_ROWS * MAX_COLS];
    int count;

    do
    {
        Write("Enter the matrix elements (e.g. [2,3],[4,4]): ");
        input = ReadLine();
        ParseNumbers(input, numbers, MAX_ROWS * MAX_COLS, out count);

        if (count != rows * cols)
            WriteLine("Incorrect number of elements. Expected " + rows * cols + " elements.");
    } while (count != rows * cols);

    int idx = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat[i, j] = numbers[idx++];
}

// Print the matrix
void PrintMatrix(int[,] mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Write(mat[i, j] + "\t");
        }
        WriteLine("");
    }
}

// Perform matrix addition or subtraction
void MatrixOperation(int[,] a, int[,] b, int[,] result, int rows, int cols, char op)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            if (op == '+') result[i, j] = a[i, j] + b[i, j];
            if (op == '-') result[i, j] = a[i, j] - b[i, j];
        }
}

// Perform matrix multiplication
void MultiplyMatrices(int[,] a, int[,] b, int[,] result, int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsB; j++)
        {
            result[i, j] = 0;
            for (int k = 0; k < colsA; k++)
                result[i, j] += a[i, k] * b[k, j];
        }
}

// Ensure a valid matrix operation is entered
char ReadValidOperation()
{
    char operation;
    string input;

    do
    {
        Write("Enter operation (+, -, *): ");
        input = ReadLine();
        operation = input[0];
    } while (operation != '+' && operation != '-' && operation != '*');

    return operation;
}

// Main logic
int[,] mat1 = new int[MAX_ROWS, MAX_COLS];
int[,] mat2 = new int[MAX_ROWS, MAX_COLS];
int[,] result = new int[MAX_ROWS, MAX_COLS];
int rows1, cols1, rows2, cols2;

WriteLine("Matrix Operation Program");

// First matrix input
rows1 = ReadValidInteger("Enter number of rows for the first matrix: ");
cols1 = ReadValidInteger("Enter number of columns for the first matrix: ");
ReadMatrix(mat1, rows1, cols1);

// Second matrix input
rows2 = ReadValidInteger("Enter number of rows for the second matrix: ");
cols2 = ReadValidInteger("Enter number of columns for the second matrix: ");
ReadMatrix(mat2, rows2, cols2);

char operation = ReadValidOperation();

// Perform matrix operation
if (operation == '+')
{
    if (rows1 == rows2 && cols1 == cols2)
    {
        MatrixOperation(mat1, mat2, result, rows1, cols1, '+');
        WriteLine("Result of addition:");
        PrintMatrix(result, rows1, cols1);
    }
    else
        WriteLine("Matrices must have the same dimensions for addition.");
}
else if (operation == '-')
{
    if (rows1 == rows2 && cols1 == cols2)
    {
        MatrixOperation(mat1, mat2, result, rows1, cols1, '-');
        WriteLine("Result of subtraction:");
        PrintMatrix(result, rows1, cols1);
    }
    else
        WriteLine("Matrices must have the same dimensions for subtraction.");
}
else if (operation == '*')
{
    if (cols1 == rows2)
    {
        MultiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
        WriteLine("Result of multiplication:");
        PrintMatrix(result, rows1, cols2);
    }
    else
        WriteLine("Number of columns of the first matrix must equal the number of rows of the second matrix for multiplication.");
}

return 0;
