from splashkit import *

name = "Richard"
location = "        Burwood"

# Convert "Richard" to "RICHARD"
name = to_uppercase(name)
write_line(name)

# Convert "RICHARD" to "richard"
name = to_lowercase(name)
write_line(name)

# Remove all of the empty spaces at the start of "      Burwood".
write_line("Before: " + location)
location = trim(location)
write_line("After: " + location)