from splashkit import *

# Load the game data JSON
game_data = json_from_file("game_data.json")

# Read basic values
title = json_read_string(game_data, "gameTitle")
num_players = json_read_number_as_int(game_data, "numPlayers")
is_full_screen = json_read_bool(game_data, "fullScreenMode")

# write_line the values
write_line(f"Game Title: {title}")
write_line(f"Number of Players: {num_players}")
write_line(f"Full Screen Mode: {is_full_screen}")

levels = []

json_read_array_of_string(game_data, "levels", levels)

num_levels = len(levels)

for i in range(num_levels):
    write_line(f"Got level: {levels[i]}")

# Read the screen size object
game_screen_size = json_read_object(game_data, "screenSize")
width = json_read_number_as_int(game_screen_size, "width")
height = json_read_number_as_int(game_screen_size, "height")

# write_line screen size
write_line(f"Screen Width: {width}")
write_line(f"Screen Height: {height}")