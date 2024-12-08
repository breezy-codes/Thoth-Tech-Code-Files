using SplashKitSDK;

namespace RaspberryPiButtonLED
{
    public class Program
    {
        public static void Main()
        {
            SplashKit.RaspiInit();
            Pins buttonPin = (Pins)29;
            Pins ledPin = (Pins)11;
            PinValues ledState = (PinValues)0;

            SplashKit.RaspiSetMode(buttonPin, (PinModes)0);
            SplashKit.RaspiSetMode(ledPin, (PinModes)1);

            SplashKit.RaspiSetPullUpDown(buttonPin, (PullUpDown)1);

            SplashKit.OpenWindow("dummy_window", 1, 1);
            while (!SplashKit.AnyKeyPressed())
            {
                SplashKit.ProcessEvents();

                if (SplashKit.RaspiRead(buttonPin) == (PinValues)1)
                {
                    ledState = SplashKit.RaspiRead(ledPin);
                    if (ledState == (PinValues)0)
                    {
                        SplashKit.RaspiWrite(ledPin, (PinValues)1);
                    }
                    else
                    {
                        SplashKit.RaspiWrite(ledPin, (PinValues)0);
                    }
                }
            }

            SplashKit.CloseAllWindows();
            SplashKit.RaspiCleanup();
        }
    }
}
