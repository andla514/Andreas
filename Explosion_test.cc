#include "Explosion.h"
#include "Timer.h"
#include "Game.h"
#include "catch.hpp"
#include <iostream>
#include <memory>
using namespace std;

TEST_CASE("")
{
    Explosion our_explosion(1, 1, 2, false, std::make_shared<Game> ());
}