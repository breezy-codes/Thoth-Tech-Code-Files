#include "splashkit.h"

int main()
{
    string message_1 = "9781273";
    string message_2 = "23129739.13";
    string message_3 = "Hello world.";

    if (is_integer(message_1))
        write_line("Message 1 contains an integer!");

    if (is_number(message_1))
        write_line("Message 1 contains a number!");

    if (not is_integer(message_2))
        write_line("Message 2 is not an integer!");

    if (is_number(message_2))
        write_line("Message 2 contains a number!");

    if (not is_integer(message_3))
        write_line("Message 3 is not an integer!");

    if (not is_number(message_3))
        write_line("Message 3 is not a number!");

    return 0;
}