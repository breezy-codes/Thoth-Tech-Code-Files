#include "splashkit.h"

int main()
{
    string file_content;
    
    // Read the file content as a string
    file_content = file_as_string("hello.json", JSON_RESOURCE);

    // Display the content in the console
    write_line("File Contents:");
    write_line(file_content);
}
