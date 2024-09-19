using static SplashKitSDK.SplashKit;

string message_1 = "9781273";
string message_2 = "23129739.13";
string message_3 = "Hello world.";

if (IsInteger(message_1))
    WriteLine("Message 1 contains an integer!");

if (IsNumber(message_1))
    WriteLine("Message 1 contains a number!");

if (!IsInteger(message_2))
    WriteLine("Message 2 is not an integer!");

if (IsNumber(message_2))
    WriteLine("Message 2 contains a number!");

if (!IsInteger(message_3))
    WriteLine("Message 3 is not an integer!");

if (!IsNumber(message_3))
    WriteLine("Message 3 is not a number!");