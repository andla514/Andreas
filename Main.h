
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

class Main
{
    public:
    Main();

    void start_non_graphic();

    private:
    std::shared_ptr<Game> our_game;
    bool is_running{true};
    Timer game_timer{1};
};

#endif