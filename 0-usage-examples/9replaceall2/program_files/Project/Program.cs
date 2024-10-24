using static SplashKitSDK.SplashKit;

WriteLine("Please enter a sentence:");
string sentence = ReadLine();

WriteLine("Please enter the word to replace:");
string oldWord = ReadLine();

WriteLine("Please enter the new word:");
string newWord = ReadLine();

// Replace all occurrences of the old word with the new word
string modified = ReplaceAll(sentence, oldWord, newWord);

WriteLine("Modified sentence: " + modified);
