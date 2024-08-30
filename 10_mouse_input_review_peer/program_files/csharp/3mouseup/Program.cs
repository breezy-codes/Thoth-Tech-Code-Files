using SplashKitSDK;
using static SplashKitSDK.SplashKit;

OpenWindow("Mouse Inputs", 800, 600);

while (!WindowCloseRequested("Mouse Inputs"))
{
    // process user input events
    ProcessEvents();

    // change screen colour to red if left mouse button is not pressed
    if (MouseUp(MouseButton.LeftButton))
    {
        ClearScreen(ColorRed());
    }
    // change screen colour to white if left button is pressed
    else
    {
        ClearScreen(ColorWhite());
    }

    RefreshScreen(60);
}

CloseAllWindows();