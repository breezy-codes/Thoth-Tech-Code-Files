using SplashKitSDK;
using static SplashKitSDK.SplashKit;

// Create a JSON object
Json json_obj = CreateJson();
JsonSetString(json_obj, "name", "Breezy");
JsonSetNumber(json_obj, "age", 25);
JsonSetBool(json_obj, "is_active", true);

// Save the JSON object to the file
WriteLine("Saving JSON to file...");
JsonToFile(json_obj, "example.json");

// Free the JSON object
FreeJson(json_obj);
WriteLine("JSON object freed.");