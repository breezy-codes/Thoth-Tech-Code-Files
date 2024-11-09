#include "splashkit.h"
using std::to_string;

// Function for modular exponentiation
int modular_exponentiation(int base, int exponent, int modulus)
{
    int result = 1;
    base = base % modulus;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}

int main()
{
    // Declare variables for RSA algorithm inputs
    int p, q, e, m;

    // Collect inputs from the user
    write_line("Welcome to the RSA Algorithm Calculator");
    write_line("---------------------------------------");

    write("Enter a value for p: ");
    p = convert_to_integer(read_line());

    write("Enter a value for q: ");
    q = convert_to_integer(read_line());

    write("Enter a value for e: ");
    e = convert_to_integer(read_line());

    write("Enter a value for the message m: ");
    m = convert_to_integer(read_line());

    // Calculate n and phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Calculate the private key component d
    int d = 0;
    while ((d * e) % phi != 1)
    {
        d++;
    }

    // Display calculated values
    write_line("------- Display the variables -------");
    write_line("The prime numbers are: " + to_string(p) + ", " + to_string(q));
    write_line("The modulus is: " + to_string(n) + " and phi(n) is: " + to_string(phi));
    write_line("The public key is: (" + to_string(e) + ", " + to_string(n) + ")");
    write_line("The private key is: (" + to_string(d) + ", " + to_string(n) + ")");
    write_line("------- Calculating the message -------");
    write_line("The original message is: " + to_string(m));

    // Encrypting the message
    int c = modular_exponentiation(m, e, n);
    write_line("The encrypted message is: " + to_string(c));
    write_line("The decrypted message is: " + to_string(modular_exponentiation(c, d, n)));

    return 0;
}
