#include "splashkit.h"

int main()
{
    string text = "  Hello!  ";

    // Trim spaces from the start and end
    string trimmed = trim(text);

    write_line("Trimmed string: '" + trimmed + "'");

    return 0;
}
