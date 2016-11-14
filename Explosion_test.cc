#include "Explosion.h"
#include "Timer.h"
#include "Game.h"
#include "catch.hpp"
#include <iostream>
#include <memory>

TEST_CASE("")
{
	Timer t(2);
    Explosion our_explosion(1, 1, t, false, std::make_shared<Game>());
}