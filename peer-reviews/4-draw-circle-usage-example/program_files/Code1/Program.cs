﻿using SplashKitSDK;
using static SplashKitSDK.SplashKit;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SPIDER_RADIUS = 25;
const int SPIDER_SPEED = 3;

// Set the spider in the center of the screen
int spiderX = SCREEN_WIDTH / 2;
int spiderY = SCREEN_HEIGHT / 2;

OpenWindow("Fly Catch", SCREEN_WIDTH, SCREEN_HEIGHT);

// The event loop
while (!QuitRequested())
{
    // Handle Input
    if (KeyDown(KeyCode.RightKey) && spiderX + SPIDER_RADIUS < SCREEN_WIDTH)
    {
        spiderX += SPIDER_SPEED;
    }

    if (KeyDown(KeyCode.LeftKey) && spiderX - SPIDER_RADIUS > 0)
    {
       spiderX -= SPIDER_SPEED;
    }

    // Draw the game
    ClearScreen(ColorWhite());
    // Draw the spider
    FillCircle(ColorBlack(), spiderX, spiderY, SPIDER_RADIUS);
    // Show it to  the user
    RefreshScreen(60);

    // Get any new user interactions
    ProcessEvents();
}