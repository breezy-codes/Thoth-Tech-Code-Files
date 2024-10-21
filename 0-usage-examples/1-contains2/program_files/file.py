from splashkit import *

write_line("Please enter a sentence:")
sentence = read_line()

if contains(sentence, "SplashKit"):
    write_line("Your sentence contains the word 'SplashKit'.")
else:
    write_line("Your sentence does not contain 'SplashKit'.")