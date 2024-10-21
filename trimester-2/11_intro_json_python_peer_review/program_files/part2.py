from splashkit import *

def main():

    game_data = json_from_file("game_data.json")
    
    if json_has_key(game_data, "gameTitle"):
        game_title = json_read_string(game_data, "gameTitle")
        print("Game Title:", game_title)
    else:
        print('Key "gameTitle" not found.')
    
    free_json(game_data)

if __name__ == "__main__":
    main()