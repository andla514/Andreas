
#ifndef MAIN_H
#define MAIN_H
#include "Game.h"
#include "Character.h"
#include "Timer.h"
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include "SFML/Graphics.hpp"

class Main
{
    public:
    Main();

    void start_non_graphic();

    private:
    sf::RenderWindow our_window;
    std::shared_ptr<Game> our_game;
    bool is_running{true};
    Timer game_timer{0.016};
};

#endif