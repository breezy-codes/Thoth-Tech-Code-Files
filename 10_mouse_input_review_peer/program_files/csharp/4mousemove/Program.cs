using SplashKitSDK;
using static SplashKitSDK.SplashKit;

// colour variables
double hue = 0.8;
double saturation = 0.8;
double brightness = 0.8;

// mouse movement variable
Vector2D movement;

OpenWindow("Mouse Movement", 800, 600);

while (!WindowCloseRequested("Mouse Movement"))
{
    // process user input events
    ProcessEvents();

    // store the mouse movement direction and distance to the movement variable
    movement = MouseMovement();

    // change screen colour 'hue' if left mouse button is held down
    if (MouseDown(MouseButton.LeftButton))
    {
        // change hue of screen colour based on horizontal mouse movement
        hue += movement.X / ScreenWidth();
    }
    // change screen colour 'saturation' if right mouse button is held down
    if (MouseDown(MouseButton.RightButton))
    {
        // change saturation of screen colour based on vertical mouse movement
        saturation += movement.Y / ScreenHeight();
    }

    // display current screen colour
    ClearScreen(HSBColor(hue, saturation, brightness));
    RefreshScreen(60);
}

CloseAllWindows();