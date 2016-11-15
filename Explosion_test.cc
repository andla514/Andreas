#include "Explosion.h"
#include "Timer.h"
#include "Game.h"
#include "catch.hpp"
#include <iostream>
#include <memory>
using namespace std;

TEST_CASE("")
{
	Game G ();
	Game* g;
	g = &G;
    Explosion our_explosion(1, 1, 2, false, g);
}