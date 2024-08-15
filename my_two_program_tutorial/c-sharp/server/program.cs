using System;
using SplashKitSDK;

ServerSocket server = null;
try
{
    // Create the server
    server = SplashKit.CreateServer("MyServer", 65432);
    SplashKit.WriteLine("Server 'MyServer' started, listening on port 65432");

    while (true)
    {
        // Check for new connections and network activity
        SplashKit.CheckNetworkActivity();

        if (SplashKit.AcceptNewConnection(server))
        {
            Connection clientConnection = SplashKit.LastConnection(server);
            uint clientIp = SplashKit.ConnectionIP(clientConnection);
            SplashKit.WriteLine("Connected by " + clientIp);

            while (SplashKit.IsConnectionOpen(clientConnection))
            {
                // Read message data from the connection
                if (SplashKit.HasMessages(clientConnection))
                {
                    string data = SplashKit.ReadMessageData(clientConnection);
                    SplashKit.WriteLine("Message read attempt...");
                    if (string.IsNullOrEmpty(data))
                    {
                        break;
                    }
                    SplashKit.WriteLine("Received from client: " + data);

                    // Send confirmation back to the client
                    string confirmationMessage = "Server received the message: " + data;
                    SplashKit.SendMessageTo(confirmationMessage, clientConnection);
                    SplashKit.WriteLine("Responded to client " + clientIp);
                }
                SplashKit.CheckNetworkActivity();
            }

            // Client disconnected
            SplashKit.WriteLine("Client " + clientIp + " disconnected.");
        }
    }
}
catch (Exception e)
{
    SplashKit.WriteLine("Server error: " + e.Message);
}

if (server != null)
{
    SplashKit.CloseServer(server);
}
SplashKit.WriteLine("Server closed.");