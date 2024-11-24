#include "splashkit.h"

int main()
{
    write_line("Pyramid Pattern Demo");


    // Height of the pyramid
    int height = 5;

    // Generate each level of the pyramid
    for (int i = 0; i < height; i++)
    {
        string line = "";

        // Add leading spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            line += " ";
        }

        // Add the '*' characters for the pyramid level
        for (int k = 0; k < 2 * i + 1; k++)
        {
            line += "*";
        }

        // Print the constructed line
        write_line(line);
    }

    // Delay to view output before the console closes
    delay(1000); // 10 seconds delay

    return 0;
}
