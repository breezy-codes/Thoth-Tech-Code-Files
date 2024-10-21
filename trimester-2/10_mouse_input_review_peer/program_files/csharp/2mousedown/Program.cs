using SplashKitSDK;
using static SplashKitSDK.SplashKit;

OpenWindow("Mouse Inputs", 800, 600);

while (!WindowCloseRequested("Mouse Inputs"))
{
    // process user input events
    ProcessEvents();

    // change screen colour to red if left mouse button is held down
    if (MouseDown(MouseButton.LeftButton))
    {
        ClearScreen(ColorRed());
    }
    // change screen colour to yellow if right mouse button is held down
    else if (MouseDown(MouseButton.RightButton))
    {
        ClearScreen(ColorYellow());
    }
    // change screen colour to white if no mouse button held down
    else
    {
        ClearScreen(ColorWhite());
    }

    RefreshScreen(60);
}

CloseAllWindows();