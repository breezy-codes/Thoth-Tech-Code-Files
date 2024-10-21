using static SplashKitSDK.SplashKit;

static int ReadInteger(string prompt)
{
    // Prompt the user with the message
    Write(prompt);

    // Read the user input as a string.
    string line = ReadLine();

    // Loop while the user's input is NOT a valid whole number.
    while (!IsInteger(line))
    {
        // If the user input was not a valid whole number, ask them to enter a whole number.
        WriteLine("Please enter a whole number.");
        Write(prompt);
        line = ReadLine();
    }
    // Convert the user input to an integer before returning it.
    return ConvertToInteger(line);
}

// Start of "main" code
int height;

height = ReadInteger("Enter your height in centimetres: ");
Write("You are ");
Write(height);
WriteLine("cm tall!");