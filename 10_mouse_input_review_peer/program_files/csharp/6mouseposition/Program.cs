using SplashKitSDK;
using static SplashKitSDK.SplashKit;

OpenWindow("Mouse Location", 800, 600);

while (!WindowCloseRequested("Mouse Location"))
{
    // process user input events
    ProcessEvents();

    // draw blue circle at mouse position
    ClearScreen(ColorWhite());
    FillCircle(ColorLightBlue(), CircleAt(MousePosition(), 20));
    RefreshScreen(60);
}

CloseAllWindows();