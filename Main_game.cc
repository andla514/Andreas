#include "Game.h"
#include "Character.h"
#include "Timer.h"
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>

int main()
{
    bool is_running = true;
    std::shared_ptr<Game> our_game = std::make_shared<Game>();
    Character our_character{our_game, 1};
    Timer game_timer{1};

    while(is_running)
    {
        system("CLS");
        our_game->update();
        our_character.update();

        int old_value = our_game->get_element(our_character.get_row(), our_character.get_col());
        our_game->set_element(our_character.get_row(), our_character.get_col(), 6);

        our_game->draw_graphics();

        our_game->set_element(our_character.get_row(), our_character.get_col(), old_value);

        game_timer.stop();
        std::cout << "Runtime: " << game_timer.elapsed_time() << std::endl;
        std::cout << "Time left: " << game_timer.time_left() << "ms" << std::endl;
        std::cout << "Character position: " << "Row: " << our_character.get_row() << " Col: " << our_character.get_col() << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(game_timer.time_left()));
        game_timer.restart();
    }
}