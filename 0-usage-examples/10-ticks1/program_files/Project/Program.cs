using static SplashKitSDK.SplashKit;

// Get the ticks before delay
uint ticksBefore = CurrentTicks();
WriteLine("Ticks before: " + ticksBefore);

// Delay for 10 seconds (10000 milliseconds)
Delay(10000);

// Get the ticks after delay
uint ticksAfter = CurrentTicks();
WriteLine("Ticks after: " + ticksAfter);
