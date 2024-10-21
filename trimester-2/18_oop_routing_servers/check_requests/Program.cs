using SplashKitSDK;

namespace WebServerApp
{
    public class Program
    {
        public static void Main()
        {
            SplashKit.WriteLine("About to start the server...");

            WebServer server = SplashKit.StartWebServer();
            HttpRequest request;

            SplashKit.WriteLine("Waiting for a request - navigate to http://localhost:8080");

            // Get the next request that the server has
            request = SplashKit.NextWebRequest(server);

            SplashKit.WriteLine("I got a request for " + SplashKit.RequestURI(request));

            if (SplashKit.IsGetRequestFor(request, "/login") || SplashKit.IsGetRequestFor(request, "/login.html"))
            {
            // Serve page for login path
            SplashKit.SendResponse(request, "login page");
            }
            else
            {
            // If no specified path is requested, serve index.html to the user
            SplashKit.SendHtmlFileResponse(request, "index.html");
            }

            SplashKit.WriteLine("About to stop the server...");
            SplashKit.StopWebServer(server);
        }
    }
}