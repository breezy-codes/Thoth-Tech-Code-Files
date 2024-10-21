using SplashKitSDK;
using static SplashKitSDK.SplashKit;
float x = 0;

OpenWindow("Mouse Location", 800, 600);

while (!WindowCloseRequested("Mouse Location"))
{
    // process user input events
    ProcessEvents();

    if (MouseDown(MouseButton.LeftButton))
    {
        x = MouseX();
    }

    ClearScreen(ColorWhite());
    FillCircle(ColorBlue(), 400, 300, 100);
    // draw purple "curtain" from left side of screen to x coordinate of mouse
    FillRectangle(ColorPurple(), 0, 0, x, ScreenHeight());
    RefreshScreen(60);
}

CloseAllWindows();