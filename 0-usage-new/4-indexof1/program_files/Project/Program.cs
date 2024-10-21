using static SplashKitSDK.SplashKit;

string sentence = "The cat is on the roof.";
string word = "cat";
WriteLine("Sentence: " + sentence);
WriteLine("Word: " + word);

// Find index of the word "cat"
int index = IndexOf(sentence, word);

WriteLine("The index of the word 'cat' is: " + index);