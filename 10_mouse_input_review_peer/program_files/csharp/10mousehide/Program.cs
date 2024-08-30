using SplashKitSDK;
using static SplashKitSDK.SplashKit;

// create cirle variable for "black hole"
Circle blackHole;

OpenWindow("Mouse Visibility", 800, 600);

// create black hole in centre of screen
blackHole = CircleAt(ScreenCenter(), 50);

while (!WindowCloseRequested("Mouse Visibility"))
{
    // process user input events
    ProcessEvents();

    // mouse disappears in black hole
    if (PointInCircle(MousePosition(), blackHole))
    {
        HideMouse();
    }
    // mouse reappears once out of black hole
    else
    {
        ShowMouse();
    }

    // display "black hole" on screen
    ClearScreen(ColorWhite());
    FillCircle(ColorBlack(), blackHole);
    RefreshScreen(60);
}

CloseAllWindows();