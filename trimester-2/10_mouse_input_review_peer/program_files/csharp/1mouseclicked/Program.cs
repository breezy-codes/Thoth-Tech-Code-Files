using SplashKitSDK;
using static SplashKitSDK.SplashKit;

OpenWindow("Mouse Inputs", 800, 600);

while (!WindowCloseRequested("Mouse Inputs"))
{
    // process user input events
    ProcessEvents();

    // change screen colour to red if left mouse button is clicked
    if (MouseClicked(MouseButton.LeftButton))
    {
        ClearScreen(ColorRed());
    }
    // change screen colour to yellow if right mouse button is clicked
    else if (MouseClicked(MouseButton.RightButton))
    {
        ClearScreen(ColorYellow());
    }

    RefreshScreen(60);
}

CloseAllWindows();