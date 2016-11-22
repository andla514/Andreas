
#ifndef MAIN_H
#define MAIN_H
#include "Game.h"
#include "Timer.h"
#include <memory>
#include "SFML/Graphics.hpp"

class Main
{
    public:
    Main();

    void start();

    private:
    sf::RenderWindow our_window;
    Game our_game;
    bool is_running{true};
    Timer physics_timer{0.016};
    Timer graphics_timer{0.016};
};

#endif