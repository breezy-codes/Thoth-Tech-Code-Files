using SplashKitSDK;
using static SplashKitSDK.SplashKit;

// Load the game data JSON file
Json gameData = JsonFromFile("game_data.json");

// Read the game data from the JSON
string title = JsonReadString(gameData, "gameTitle");
int numPlayers = JsonReadNumberAsInt(gameData, "numPlayers");
bool isFullScreen = JsonReadBool(gameData, "fullScreenMode");
List<string> levels = new List<string>();

// Write the game data to the terminal
WriteLine($"Game Title: {title}");
WriteLine($"Number of Players: {numPlayers}");
WriteLine($"Full Screen Mode: {isFullScreen}");

// Read the levels array from the JSON
JsonReadArray(gameData, "levels", ref levels);

int numLevels = levels.Count;

for (int i = 0; i < numLevels; i++)
{
    WriteLine($"Got level: {levels[i]}");
}

// Extract the nested JSON objects
Json gameScreenSize = JsonReadObject(gameData, "screenSize");
int width = JsonReadNumberAsInt(gameScreenSize, "width");
int height = JsonReadNumberAsInt(gameScreenSize, "height");

// Write the screen size to the terminal
WriteLine($"Screen Width: {width}");
WriteLine($"Screen Height: {height}");