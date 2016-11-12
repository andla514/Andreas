#include "Game.h"
#include "Character.h"
#include <unistd.h>
#include <stdlib.h>
#include "windows.h"
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    bool is_running = true;
    Game our_game;
    while(is_running)
    {
        system("CLS");
        our_game.draw_graphics();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}