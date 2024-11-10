using SplashKitSDK;

namespace DrawCircleOnBitmap
{
    public class Program
    {
        public static void Main()
        {
            // Create a bitmap to draw on
            Bitmap planet = new Bitmap("planet", 400, 400);
            
            // Fill background with dark color
            SplashKit.ClearBitmap(planet, SplashKit.ColorBlack());
            
            // Create color
            Color red = SplashKit.ColorRed();
            
            // Draw the main planet circle
            SplashKit.FillCircleOnBitmap(planet, SplashKit.RGBAColor(180, 0, 0, 255), 200, 200, 150);
            SplashKit.DrawCircleOnBitmap(planet, red, 200, 200, 150);
            
            // Add some surface details with smaller circles
            for(int i = 0; i < 15; i++)
            {
                double x = SplashKit.Rnd(100, 300);  // Random between 100 and 300
                double y = SplashKit.Rnd(100, 300);  // Random between 100 and 300
                double size = SplashKit.Rnd(10, 30);  // Random between 10 and 30
                SplashKit.DrawCircleOnBitmap(planet, red, x, y, size);
            }
            
            // Save and free the bitmap
            SplashKit.SaveBitmap(planet, "draw_circle_on_bitmap-1-red-planet");
            SplashKit.FreeBitmap(planet);
        }
    }
}
