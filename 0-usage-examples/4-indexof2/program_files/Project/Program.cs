using static SplashKitSDK.SplashKit;

WriteLine("Please enter a sentence:");
string sentence = ReadLine();

WriteLine("Please enter the word to find:");
string word = ReadLine();

// Find index of the word in the sentence
int index = IndexOf(sentence, word);

WriteLine("The index of the word is: " + index);