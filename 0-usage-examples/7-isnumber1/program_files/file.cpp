#include "splashkit.h"

int main()
{
    string values[6] = {"123", "45.67", "hello", "abc", "-789", "0"};

    write_line("Let's check if these values are numbers:");

    for (int i = 0; i < 6; i++)
    {
        // Check if string is a valid number
        bool is_number_value = is_number(values[i]);

        // Print the value along with the result using a clearer message
        if (is_number_value)
        {
            write_line("'" + values[i] + "' is a valid number: true");
        }
        else
        {
            write_line("'" + values[i] + "' is not a valid number: false");
        }
    }

    return 0;
}
