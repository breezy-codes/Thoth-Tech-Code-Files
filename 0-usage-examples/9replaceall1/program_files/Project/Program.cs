using static SplashKitSDK.SplashKit;

string sentence = "I like apple pie. Apple is great.";

// Replace all occurrences of "apple" with "orange"
string modified = ReplaceAll(sentence, "apple", "orange");

WriteLine("Modified sentence: " + modified);
