#include "Game.h"
#include "Character.h"
#include "Timer.h"
#include "Main.h"
#include <iostream>
#include <memory>
#include "SFML/Graphics.hpp"

//-----------------CONSTRUCTOR--------------
Main::Main()
{
    our_game.add_characters(3);
    our_window.create(sf::VideoMode{1344, 960}, "Boombox");
}

void Main::start()
{
    physics_timer.restart();
    graphics_timer.restart();

    // Game loop
    while(is_running)
    {
        // Handle window-action
        sf::Event our_event;
        while (our_window.pollEvent(our_event))
        {
            if (our_event.type == sf::Event::Closed)
            {
                our_window.close();
            }
        }
        // Update physics
        if(physics_timer.is_done())
        {
            our_game.update();
            physics_timer.restart();
        }
        // Update Graphics
        if(graphics_timer.is_done())
        {
            our_window.clear();
            our_game.draw_graphics(our_window);
            our_window.display();
            graphics_timer.restart();
        }

        sf::sleep(sf::milliseconds(1));
    }
}