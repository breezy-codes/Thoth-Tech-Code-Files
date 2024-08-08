using SplashKitSDK;

SplashKit.WriteLine("About to start the server...");

// Start a web server - defaults to listening to port 8080
WebServer server = SplashKit.StartWebServer();

SplashKit.WriteLine("Waiting for a request - navigate to http://localhost:8080");

// Wait and get the first request that comes in
HttpRequest request = SplashKit.NextWebRequest(server);

// Send back the index.html file
SplashKit.SendHtmlFileResponse(request, "index.html");

// For now, we are done, so let's shutdown
SplashKit.StopWebServer(server);

SplashKit.ReadLine(); // Pause to keep the console window open