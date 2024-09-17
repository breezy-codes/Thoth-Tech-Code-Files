using SplashKitSDK;

namespace CameraGame
{
    public class Program
    {
        public static void Main()
        {
            const int ScreenWidth = 800;
            const int ScreenHeight = 800;
            const int ScreenBorder = 100;
            const double PlayerSpeed = 3;

            Window window = SplashKit.OpenWindow("Camera Test", ScreenWidth, ScreenHeight);
            double playerX = ScreenWidth / 2;
            double playerY = ScreenHeight / 2;
            double cameraX = 0;
            double cameraY = 0;

            while (!window.CloseRequested)
            {
                // Handle input
                if (SplashKit.KeyDown(KeyCode.LeftKey)) playerX -= PlayerSpeed;
                if (SplashKit.KeyDown(KeyCode.RightKey)) playerX += PlayerSpeed;
                if (SplashKit.KeyDown(KeyCode.DownKey)) playerY += PlayerSpeed;
                if (SplashKit.KeyDown(KeyCode.UpKey)) playerY -= PlayerSpeed;

                // Update camera position
                double leftEdge = cameraX + ScreenBorder;
                double rightEdge = leftEdge + ScreenWidth - 2 * ScreenBorder;
                double topEdge = cameraY + ScreenBorder;
                double bottomEdge = topEdge + ScreenHeight - 2 * ScreenBorder;

                if (playerY < topEdge) cameraY += topEdge - playerY;
                else if (playerY > bottomEdge) cameraY += bottomEdge - playerY;

                if (playerX < leftEdge) cameraX += leftEdge - playerX;
                else if (playerX > rightEdge) cameraX += rightEdge - playerX;

                // Draw everything
                window.Clear(Color.Black);
                window.FillRectangle(Color.Gray, 0 - cameraX, 0 - cameraY, ScreenWidth, 50);
                window.DrawText("HUD", Color.White, 10 - cameraX, 10 - cameraY);
                window.DrawText($"Camera Position: {cameraX:0.00000}:{cameraY:0.00000}", Color.White, 10 - cameraX, 30 - cameraY);
                window.FillCircle(Color.Yellow, playerX - cameraX, playerY - cameraY, 20);
                window.FillRectangle(Color.White, 400 - cameraX, 200 - cameraY, 10, 10);
                SplashKit.RefreshScreen(60);
            }

            SplashKit.CloseAllWindows();
        }
    }
}