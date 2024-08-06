using System;
using SplashKitSDK;

public class Client
{
    public static void StartClient(string name, string host = "127.0.0.1", int port = 65432)
    {
        // Create the client connection
        Connection client = SplashKit.OpenConnection(name, host, (ushort)port);
        SplashKit.WriteLine("Connected to server at " + host + ":" + port);

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
    }

    public static void Main()
    {
        StartClient("MyClient", "127.0.0.1", 65432);
    }
}
