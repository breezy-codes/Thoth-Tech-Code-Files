using SplashKitSDK;
using static SplashKitSDK.SplashKit;

const int SCREEN_BORDER = 100;

static void UpdateCameraPosition(double playerX, double playerY)
{
    // Test edge of screen boundaries to adjust the camera
    double leftEdge = Camera.X + SCREEN_BORDER;
    double rightEdge = leftEdge + ScreenWidth() - 2 * SCREEN_BORDER;
    double topEdge = Camera.Y + SCREEN_BORDER;
    double bottomEdge = topEdge + ScreenHeight() - 2 * SCREEN_BORDER;

    // Test if the player is outside the area and move the camera
    // the player will appear to stay still and everything else
    // will appear to move :)

    // Test top/bottom of screen
    if (playerY < topEdge)
    {
        MoveCameraBy(0, playerY - topEdge);
    }
    else if (playerY > bottomEdge)
    {
        MoveCameraBy(0, playerY - bottomEdge);
    }

    // Test left/right of screen
    if (playerX < leftEdge)
    {
        MoveCameraBy(playerX - leftEdge, 0);
    }
    else if (playerX > rightEdge)
    {
        MoveCameraBy(playerX - rightEdge, 0);
    }
}

// Start of "main" code
OpenWindow("Camera Test", 800, 800);

double playerX = 400, playerY = 400;

while (!QuitRequested())
{
    // Handle input to adjust player movement
    ProcessEvents();

    if (KeyDown(KeyCode.LeftKey))
        playerX -= 3;
    if (KeyDown(KeyCode.RightKey))
        playerX += 3;
    if (KeyDown(KeyCode.DownKey))
        playerY += 3;
    if (KeyDown(KeyCode.UpKey))
        playerY -= 3;

    UpdateCameraPosition(playerX, playerY);

    // Redraw everything
    ClearScreen(ColorBlack());

    // Draw to the screen
    FillRectangle(ColorDimGray(), 0, 0, ScreenWidth(), 50, OptionToScreen());
    DrawText("HUD", ColorWhite(), 10, 10, OptionToScreen());
    DrawText("Camera Position: " + PointToString(Camera.Position), Color.White, 10, 30, OptionToScreen());

    // as well as the player who can move
    FillCircle(ColorYellow(), playerX, playerY, 20);

    // including something stationary - it doesn't move
    FillRectangle(ColorWhite(), 400, 200, 10, 10);

    RefreshScreen(60);
}
CloseAllWindows();