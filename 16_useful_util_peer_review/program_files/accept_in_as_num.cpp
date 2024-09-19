#include "splashkit.h"
#include <string>

using namespace std;

/**
* Reads input from a user, only allowing whole numbers.
* @prompt string     - The string to display to the user.
* @return int
*/
int read_integer(string prompt)
{

  // Prompt the user with the message
  write(prompt);

  // Read the user input as a string.
  string line = read_line();

  // Check if user input is a valid whole number, loop until it is.
  while (!is_integer(line))
  {
      write_line("Please enter a whole number.");

      write(prompt);
      line = read_line();
  }

  // Convert the user input to an integer before returning it.
  return convert_to_integer(line);
}

int main()
{
  int height;

  height = read_integer("Enter your height in centimetres: ");
  write("You are ");
  write(height);
  write_line("CM tall!");

  return 0;
}