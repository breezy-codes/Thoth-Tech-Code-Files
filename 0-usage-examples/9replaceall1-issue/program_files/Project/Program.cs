using SplashKitSDK;

namespace Program
{
    public class Program
    {
        public static void Main()
        {
            string sentence = "The robot loves apple juice. Apple is its favourite fruit.";

            // Display the original sentence
            SplashKit.WriteLine("Original sentence: " + sentence);

            // Replace all occurrences of "apple" with "bolts"
            string modified = SplashKit.ReplaceAll(sentence, "apple", "bolts");

            // Display the modified sentence
            SplashKit.WriteLine("Modified sentence: " + modified);
        }
    }
}
