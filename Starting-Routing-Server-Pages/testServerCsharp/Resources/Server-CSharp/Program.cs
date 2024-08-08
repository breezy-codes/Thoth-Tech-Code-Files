using SplashKitSDK;

SplashKit.WriteLine("About to start the server...");

WebServer server = SplashKit.StartWebServer();
HttpRequest request;

SplashKit.WriteLine("Waiting for a request - navigate to http://localhost:8080");
SplashKit.WriteLine("To end - navigate to http://localhost:8080/quit");

// Get the next request that the server has
request = SplashKit.NextWebRequest(server);

while (!SplashKit.IsGetRequestFor(request, "/quit"))
{
    SplashKit.WriteLine("I got a request for " + SplashKit.RequestURI(request));

    if (SplashKit.IsGetRequestFor(request, "/login") || SplashKit.IsGetRequestFor(request, "/login.html"))
    {
        // Serve page for login path, e.g.
        // SendHtmlFileResponse(request, "login.html");

        SplashKit.SendResponse(request, "login page");
    }
    else if (SplashKit.IsGetRequestFor(request, "/contact") || SplashKit.IsGetRequestFor(request, "/contact.html"))
    {
        // Serve page for contact path, e.g.
        // SendHtmlFileResponse(request, "contact.html");

        SplashKit.SendResponse(request, "contact page");
    }
    else if (SplashKit.IsGetRequestFor(request, "/about") || SplashKit.IsGetRequestFor(request, "/about.html"))
    {
        // Serve page for about path, e.g.
        // SendHtmlFileResponse(request, "about.html");

        SplashKit.SendResponse(request, "about page");
    }
    else
    {
        // If no specified path is requested, serve index.html to the user
        SplashKit.SendHtmlFileResponse(request, "index.html");
    }

    SplashKit.WriteLine("Waiting for a request - navigate to http://localhost:8080");
    SplashKit.WriteLine("To end - navigate to http://localhost:8080/quit");

    // Get the next request that the server has
    request = SplashKit.NextWebRequest(server);
}

SplashKit.WriteLine("About to stop the server...");
SplashKit.StopWebServer(server);