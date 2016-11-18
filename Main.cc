#include "Game.h"
#include "Character.h"
#include "Timer.h"
#include "Main.h"
#include <stdlib.h>
#include <iostream>
#include <memory>
#include "SFML/Graphics.hpp"

//-----------------CONSTRUCTOR--------------
Main::Main()
{
    our_game = std::make_unique<Game>();
    our_game->add_characters(3, our_game);
    our_window.create(sf::VideoMode{1344, 960}, "Boombox");
}

void Main::start_non_graphic()
{
    //int old_value [3];
    game_timer.restart();
    while(is_running)
    {
        sf::Event our_event;
        while (our_window.pollEvent(our_event))
        {
            if (our_event.type == sf::Event::Closed)
            {
                our_window.close();
            }
        }
        
        if(game_timer.is_done())
        {
            //system("CLS");
            our_game->update();
/*
            for(int i = 0; i < 3; i++)
            {
                Character our_character = our_game->get_character_reference(i + 1);
                old_value[i] = our_game->get_element(our_character.get_row(), our_character.get_col());
                our_game->set_element(our_character.get_row(), our_character.get_col(), 6);
            }
            // Draws all graphics
            */
            our_window.clear();
            our_game->draw_graphics(our_window);
            our_window.display();
            //our_game->draw_graphics();
/*
            for(int i = 0; i < 3; i++)
            {
                Character our_character = our_game->get_character_reference(i + 1);
                our_game->set_element(our_character.get_row(), our_character.get_col(), old_value[i]);
            }
*/
            game_timer.restart();
        }
        sf::sleep(sf::milliseconds(15));
    }
}