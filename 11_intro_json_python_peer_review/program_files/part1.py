from splashkit import *

def main():

    game_data = json_from_file("game_data.json")
    game_title = json_read_string(game_data, "gameTitle")

    if not game_title:
        print("Error retrieving gameTitle.")
    else:
        print("Game Title:", game_title)
    
    free_json(game_data)


if __name__ == "__main__":
    main()