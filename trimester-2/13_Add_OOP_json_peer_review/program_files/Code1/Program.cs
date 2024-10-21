using SplashKitSDK;

namespace GameDataManagement
{
  public class Program
  {
      public static void Main()
      {
          // Define the file path
          string filePath = "game_data.json";

          // Load JSON data from file
          Json gameData = SplashKit.JsonFromFile(filePath);

          // Read game title from JSON
          string gameTitle = SplashKit.JsonReadString(gameData, "gameTitle");

          // Output the game title to the terminal
          SplashKit.WriteLine("Game Title: " + gameTitle);

          // Free the JSON data
          SplashKit.FreeJson(gameData);
      }
  }
}