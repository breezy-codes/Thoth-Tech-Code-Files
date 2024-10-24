#include "splashkit.h"

int main()
{
    string values[6] = {"123", "45.67", "hello", "abc", "-789", "0"};

    for (int i = 0; i < 6; i++)
    {
        // Check if string is a valid integer
        bool integer = is_number(values[i]);

        // Print the value along with the result using "true" or "false"
        write_line(values[i] + " - " + (integer ? "true" : "false"));
    }

    return 0;
}
