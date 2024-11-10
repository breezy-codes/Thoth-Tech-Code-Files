﻿using static SplashKitSDK.SplashKit;

// Create a bitmap to draw on
Bitmapplanet = CreateBitmap("planet", 400, 400);

// Fill background with dark color
ClearBitmap(planet, ColorBlack());

// Draw the main planet circle
FillCircleOnBitmap(planet, RGBAColor(180, 0, 0, 255), 200, 200, 150);
DrawCircleOnBitmap(planet, ColorRed, 200, 200, 150);

// Add some surface details with smaller circles
for(int i = 0; i < 15; i++)
{
    double x = Rnd(100, 300);  // Random between 100 and 300
    double y = Rnd(100, 300);   // Random between 100 and 300
    double size = Rnd(10, 30);  // Random between 10 and 30
    DrawCircleOnBitmap(planet, ColorRed, x, y, size);
}

// Save and free the bitmap
SaveBitmap(planet, "red_planet");
FreeBitmap(planet);