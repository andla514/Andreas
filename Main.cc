#include "Game.h"
#include "Character.h"
#include "Timer.h"
#include "Main.h"
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include "SFML/Graphics.hpp"

//-----------------CONSTRUCTOR--------------
Main::Main()
{
    our_game = std::make_unique<Game>();
    our_game->add_characters(3, our_game);
    our_window.create(sf::VideoMode{800, 600}, "Boombox");
}

void Main::start_non_graphic()
{
    int old_value [3];
    game_timer.restart();
    while(is_running)
    {
        system("CLS");
        our_game->update();

        for(int i = 0; i < 3; i++)
        {
            Character our_character = our_game->get_character_reference(i + 1);
            old_value[i] = our_game->get_element(our_character.get_row(), our_character.get_col());
            our_game->set_element(our_character.get_row(), our_character.get_col(), 6);
        }

        our_game->draw_graphics();

    for(int i = 0; i < 3; i++)
        {
            Character our_character = our_game->get_character_reference(i + 1);
            our_game->set_element(our_character.get_row(), our_character.get_col(), old_value[i]);
        }

        game_timer.stop();
        std::cout << "Runtime: " << game_timer.elapsed_time() << std::endl;
        std::cout << "Time left: " << game_timer.time_left() << "ms" << std::endl;
        //std::cout << "Character position: " << "Row: " << our_character.get_row() << " Col: " << our_character.get_col() << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(game_timer.time_left()));
        game_timer.restart();
    }
}