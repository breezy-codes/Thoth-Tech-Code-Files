using SplashKitSDK;
using static SplashKitSDK.SplashKit;

OpenWindow("Mouse Location", 800, 600);

while (!WindowCloseRequested("Mouse Location"))
{
    // process user input events
    ProcessEvents();

    // draw line from mouse position vector
    ClearScreen(ColorWhite());
    DrawLine(ColorBlue(), LineFrom(MousePositionVector()));
    RefreshScreen(60);
}

CloseAllWindows();