using SplashKitSDK;
using static SplashKitSDK.SplashKit;

const int MAX_DEGREE = 100;  // Define a maximum degree for polynomials

// Ensure the user enters a valid integer
int ReadValidInteger(string prompt)
{
    int number;
    Write(prompt);
    string input = ReadLine();

    while (!IsInteger(input))
    {
        WriteLine("Invalid integer input. Please enter a valid integer.");
        Write(prompt);
        input = ReadLine();
    }

    number = ConvertToInteger(input);
    return number;
}

// Read a polynomial from the user
void ReadPolynomial(int[] poly, out int degree)
{
    degree = ReadValidInteger("Enter the degree of the polynomial: ");

    for (int i = degree; i >= 0; i--)
    {
        poly[i] = ReadValidInteger("Enter coefficient for x^" + i + ": ");
    }

    // Initialise unused coefficients (those beyond the entered degree) to 0
    for (int i = degree + 1; i <= MAX_DEGREE; i++)
    {
        poly[i] = 0;
    }
}

// Print a polynomial to the console
void PrintPolynomial(int[] poly, int degree)
{
    for (int i = degree; i >= 0; i--)
    {
        if (poly[i] != 0)
        {
            if (i != degree && poly[i] > 0)
                Write("+");
            if (i == 0 || poly[i] != 1)
                Write(poly[i].ToString());
            if (i > 0)
                Write("x");
            if (i > 1)
                Write("^" + i);
            Write(" ");
        }
    }
    WriteLine("");
}

// Add two polynomials together
void AddPolynomials(int[] a, int aDegree, int[] b, int bDegree, int[] result, out int resultDegree)
{
    resultDegree = Math.Max(aDegree, bDegree);

    for (int i = 0; i <= resultDegree; i++)
    {
        int coefA = (i <= aDegree) ? a[i] : 0;
        int coefB = (i <= bDegree) ? b[i] : 0;
        result[i] = coefA + coefB;
    }

    // Initialise any unused coefficients in result array to 0
    for (int i = resultDegree + 1; i <= MAX_DEGREE; i++)
    {
        result[i] = 0;
    }
}

// Multiply two polynomials together
void MultiplyPolynomials(int[] a, int aDegree, int[] b, int bDegree, int[] result, out int resultDegree)
{
    resultDegree = aDegree + bDegree;

    // Initialise result array to 0
    for (int i = 0; i <= resultDegree; i++)
    {
        result[i] = 0;
    }

    for (int i = 0; i <= aDegree; i++)
    {
        for (int j = 0; j <= bDegree; j++)
        {
            result[i + j] += a[i] * b[j];
        }
    }

    // Initialise any unused coefficients in result array to 0
    for (int i = resultDegree + 1; i <= MAX_DEGREE; i++)
    {
        result[i] = 0;
    }
}

// Main logic
int[] poly1 = new int[MAX_DEGREE + 1];  // Array for first polynomial
int[] poly2 = new int[MAX_DEGREE + 1];  // Array for second polynomial
int[] result = new int[MAX_DEGREE * 2 + 1];  // Result array (max possible degree = MAX_DEGREE * 2)
int degree1, degree2, resultDegree;

WriteLine("Enter the first polynomial:");
ReadPolynomial(poly1, out degree1);

WriteLine("Enter the second polynomial:");
ReadPolynomial(poly2, out degree2);

Write("Enter operation (+ or *): ");
string inputOp = ReadLine();
char operation = inputOp[0];

// Print the polynomials to show what is being added or multiplied
Write("First polynomial: ");
PrintPolynomial(poly1, degree1);

Write("Second polynomial: ");
PrintPolynomial(poly2, degree2);

if (operation == '+')
{
    AddPolynomials(poly1, degree1, poly2, degree2, result, out resultDegree);
    WriteLine("Result of addition:");
}
else if (operation == '*')
{
    MultiplyPolynomials(poly1, degree1, poly2, degree2, result, out resultDegree);
    WriteLine("Result of multiplication:");
}
else
{
    WriteLine("Invalid operation.");
    return;
}

// Print the result polynomial
PrintPolynomial(result, resultDegree);
