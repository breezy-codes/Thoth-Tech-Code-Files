using SplashKitSDK;
using static SplashKitSDK.SplashKit;

namespace SoundDemoOOP
{
    public class Program
    {
        public static void Main()
        {

            Window window = new Window("Sound Demo", 640, 320);
            SoundEffect sndEffect = LoadSoundEffect("chipmunk", "chipmunk.ogg");
            LoadSoundEffect("bells", "bells.ogg");
            LoadSoundEffect("camera", "camera.ogg");
            LoadSoundEffect("boing", "comedy_boing.ogg");
            LoadSoundEffect("dinosaur", "dinosaur.ogg");
            LoadSoundEffect("bark", "dog_bark.ogg");
            LoadFont("arial", "arial.ttf");


            do
            {
                ProcessEvents();

                if (KeyDown(KeyCode.RightCtrlKey) || KeyDown(KeyCode.LeftCtrlKey))
                {
                    if (KeyTyped(KeyCode.Num1Key))
                        sndEffect = SoundEffectNamed("chipmunk");
                    if (KeyTyped(KeyCode.Num2Key))
                        sndEffect = SoundEffectNamed("bells");
                    if (KeyTyped(KeyCode.Num3Key))
                        sndEffect = SoundEffectNamed("camera");
                    if (KeyTyped(KeyCode.Num4Key))
                        sndEffect = SoundEffectNamed("boing");
                    if (KeyTyped(KeyCode.Num5Key))
                        sndEffect = SoundEffectNamed("dinosaur");
                    if (KeyTyped(KeyCode.Num6Key))
                        sndEffect = SoundEffectNamed("bark");
                }
                else
                {
                    if (KeyTyped(KeyCode.Num1Key))
                        sndEffect.Play();
                    if (KeyTyped(KeyCode.Num2Key))
                        sndEffect.Play(0.5f);
                    if (KeyTyped(KeyCode.Num3Key))
                        sndEffect.Play(3, 0.25f);
                    if (KeyTyped(KeyCode.Num4Key))
                        sndEffect.Play(-1, 0.1f);
                    if (KeyTyped(KeyCode.Num5Key))
                    {
                        if (sndEffect.IsPlaying)
                            sndEffect.Stop();
                    }
                }

                // Clear the screen with SplashKit Orange background
                ClearScreen(RGBColor(245, 166, 35));

                // Draw heading
                SetFontStyle("arial", FontStyle.BoldFont);
                DrawText("Keyboard Controls", Color.Black, "arial", 20, (window.Width - TextWidth("Keyboard Controls", "arial", 20)) / 2, 10);
                SetFontStyle("arial", FontStyle.NormalFont);

                // Draw left box with SplashKit Cyan/Teal border
                FillRectangle(RGBColor(5, 172, 193), 10, 45, window.Width / 2 + 10, window.Height - 85);
                FillRectangle(Color.PapayaWhip, 20, 55, window.Width / 2 - 10, window.Height - 105);
                DrawLine(Color.LightGray, 30, 105, window.Width / 2, 105);

                // Playing sound effect controls text
                DrawText("Playing Sound Controls", Color.Red, "arial", 18, 80, 70);
                DrawText("[1]    Play Sound At Full Volume", Color.Blue, "arial", 14, 30, 120);
                DrawText("[2]    Play Sound At 50% Volume", Color.Blue, "arial", 14, 30, 150);
                DrawText("[3]    Play Sound 3 Times At 25% Volume", Color.Blue, "arial", 14, 30, 180);
                DrawText("[4]    Play Sound Continuously at 10% Volume", Color.Blue, "arial", 14, 30, 210);
                DrawText("[5]    Stop Playing Current Sound", Color.Blue, "arial", 14, 30, 240);

                // Exit text
                SetFontStyle("arial", FontStyle.ItalicFont);
                DrawText("Press [Escape] or [Q] to quit", Color.Black, "arial", 16, 65, 290);
                SetFontStyle("arial", FontStyle.NormalFont);

                // Draw right box with SplashKit Cyan/Teal border
                FillRectangle(RGBColor(5, 172, 193), window.Width / 2 + 30, 45, window.Width / 2 - 40, window.Height - 55);
                FillRectangle(Color.PapayaWhip, window.Width / 2 + 40, 55, window.Width / 2 - 60, window.Height - 75);
                DrawLine(Color.LightGray, window.Width / 2 + 50, 105, window.Width - 30, 105);

                // Switching to sound effect controls text
                DrawText("Switching Sound Controls", Color.OrangeRed, "arial", 18, window.Width / 2 + 65, 70);
                DrawText("[CTRL + 1]    Chipmunk Sound", Color.DarkGreen, "arial", 14, window.Width / 2 + 50, 120);
                DrawText("[CTRL + 2]    Bells Sound", Color.DarkGreen, "arial", 14, window.Width / 2 + 50, 150);
                DrawText("[CTRL + 3]    Camera Sound", Color.DarkGreen, "arial", 14, window.Width / 2 + 50, 180);
                DrawText("[CTRL + 4]    Boing Sound", Color.DarkGreen, "arial", 14, window.Width / 2 + 50, 210);
                DrawText("[CTRL + 5]    Dinosaur Sound", Color.DarkGreen, "arial", 14, window.Width / 2 + 50, 240);
                DrawText("[CTRL + 6]    Bark Sound", Color.DarkGreen, "arial", 14, window.Width / 2 + 50, 270);

                RefreshScreen(60);
            } while (!(QuitRequested() || KeyTyped(KeyCode.EscapeKey) || KeyTyped(KeyCode.QKey)));

            CloseAllWindows();
        }
    }
}