using SplashKitSDK;
using static SplashKitSDK.SplashKit;

float y = 0;

OpenWindow("Mouse Location", 800, 600);

while (!WindowCloseRequested("Mouse Location"))
{
    // process user input events
    ProcessEvents();

    if (MouseDown(MouseButton.LeftButton))
    {
        y = MouseY();
    }

    ClearScreen(ColorWhite());
    FillCircle(ColorBlue(), 400, 300, 100);
    // draw purple "curtain" from top of screen to y coordinate of mouse
    FillRectangle(ColorPurple(), 0, 0, ScreenWidth(), y);
    RefreshScreen(60);
}

CloseAllWindows();