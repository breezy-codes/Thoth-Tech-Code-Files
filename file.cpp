#include "splashkit.h"

using std::to_string;

//targets data
struct target_data{
    double y;
    double x;
    double radius;
};

//games data
struct reaction_game_data{
    target_data target;
    int hits;
};

//detects mouse over target
bool mouse_over_target(target_data target){
    return point_in_circle(mouse_x(), mouse_y(), target.x, target.y, target.radius);
}

//records time for taregt to be hit
int game_time(reaction_game_data game){
    int time;

    if (mouse_clicked(LEFT_BUTTON) && mouse_over_target(game.target)){
    return current_ticks();
    }
    else{
        return current_ticks();
    }
 }

//adding a new target
target_data new_target(double x, double y, const double radius){
target_data result;
    result.x = x;
    result.y = y;
    result.radius = radius;
    return result;
}

//random target and references radius
target_data random_target(reaction_game_data& game){
    int radius = game_time(game)/1000*200;

    return new_target(
        rnd(radius, screen_width() - radius),
        rnd(radius, screen_height() - radius),
        radius
    );
}

//Draws fucntion
void draw_target(const target_data& target){
    fill_circle(COLOR_LIGHT_SEA_GREEN, target.x, target.y, target.radius);
}

//draws game
void draw_game(reaction_game_data game){
    clear_screen(COLOR_WHITE);
    draw_text("Hits: "+to_string(game.hits), COLOR_BLACK, 0, 0);
    draw_text("Time: "+to_string(game_time(game)), COLOR_BLACK, 0, 10);

    draw_target(game.target);
    refresh_screen();
}

//reaction game data/ fucntion
reaction_game_data new_reaction_game(){
    reaction_game_data result;
    result.target = random_target(result);
    result.hits = 0;
    return result;
}

int main(){
    open_window("Reaction Timer", 800, 600);

    reaction_game_data game = new_reaction_game();
    while(!quit_requested()){
        process_events();

        if(mouse_clicked(LEFT_BUTTON) && mouse_over_target(game.target)){
            game.target = random_target(game);
            game.hits++;
            
        }

        clear_screen(COLOR_WHITE);

        draw_game(game);
    }

    return 0;
}