#include "Game.h"
#include "Character.h"
#include "Timer.h"
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    bool is_running = true;
    Game our_game;
    Timer game_timer{1};

    while(is_running)
    {
        system("CLS");
        our_game.draw_graphics();

        game_timer.stop();
        std::cout << "Runtime: " << game_timer.elapsed_time() << std::endl;
        std::cout << "Time left: " << game_timer.time_left() << "ms" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(game_timer.time_left()));
        game_timer.restart();
    }
}