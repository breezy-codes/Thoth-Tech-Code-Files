#include "splashkit.h"
int main()
{
    json game_data;
    game_data = json_from_file("game_data.json");
    string game_title = json_read_string(game_data, "gameTitle");

    write("Game Title: ");
    write_line(game_title);

    free_json(game_data);

    return 0;
}