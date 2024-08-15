using System;
using SplashKitSDK;

// Create the client connection
Connection client = SplashKit.OpenConnection("MyClient", "127.0.0.1", 65432);
SplashKit.WriteLine("Connected to server at 127.0.0.1:65432");

while (SplashKit.IsConnectionOpen(client))
{
    // Get user input
    SplashKit.Write("Enter message to send (or 'exit' to quit): ");
    string message = SplashKit.ReadLine();
    if (message.ToLower() == "exit")
    {
        break;
    }
    // Send data to the server
    SplashKit.WriteLine("Sending message: " + message);
    SplashKit.SendMessageTo(message, client);
    
    // Check for new network activity and wait for the server response
    while (true)
    {
        SplashKit.CheckNetworkActivity();
        if (SplashKit.HasMessages(client))
        {
            string msg = SplashKit.ReadMessageData(client);
            SplashKit.WriteLine("Received from server: " + msg);
            break;
        }
    }
}

// Close the client connection
SplashKit.CloseConnection(client);
SplashKit.WriteLine("Client closed.");