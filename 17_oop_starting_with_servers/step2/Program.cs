using SplashKitSDK;

namespace WebServerApp
{
    public class Program
    {
        public static void Main()
        {
            SplashKit.WriteLine("About to start the server...");

            // Start the web server (defaults to listening to port 8080)
            WebServer server = SplashKit.StartWebServer();

            // Stop the web server
            SplashKit.StopWebServer(server);
        }
    }
}
