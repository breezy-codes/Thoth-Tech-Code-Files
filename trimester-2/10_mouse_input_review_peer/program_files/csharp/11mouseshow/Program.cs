using SplashKitSDK;
using static SplashKitSDK.SplashKit;

// create cirle variable for emulating a "stage spot light"
Circle spotLight;

OpenWindow("Mouse Visibility", 800, 600);

// create a "spot light" circle in centre of screen
spotLight = CircleAt(ScreenCenter(), 100);

while (!WindowCloseRequested("Mouse Visibility"))
{
    // process user input events
    ProcessEvents();

    // mouse disappears when not in the "spot light"
    ShowMouse(PointInCircle(MousePosition(), spotLight));

    // display "spot light" on screen
    ClearScreen(ColorBlack());
    FillCircle(ColorWhite(), spotLight);
    RefreshScreen(60);
}

CloseAllWindows();