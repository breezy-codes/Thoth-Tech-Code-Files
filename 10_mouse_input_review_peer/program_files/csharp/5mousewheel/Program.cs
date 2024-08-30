using SplashKitSDK;
using static SplashKitSDK.SplashKit;

// color variables
double hue = 0.6;
double saturation = 0.6;
double brightness = 0.6;

// mouse scroll variable
Vector2D scroll;

OpenWindow("Mouse Scrolling", 800, 600);

while (!WindowCloseRequested("Mouse Scrolling"))
{
    // process user input events
    ProcessEvents();

    // store the mouse wheel scroll direction and distance to the scroll variable
    scroll = MouseWheelScroll();

    // change hue of screen colour based on vertical mouse scrolling (two fingers if using trackpad)
    hue += scroll.Y / 100;

    // display current screen colour
    ClearScreen(HSBColor(hue, saturation, brightness));
    RefreshScreen(60);
}

CloseAllWindows();