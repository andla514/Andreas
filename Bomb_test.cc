#include "Bomb.h"
#include "Game.h"
#include "Timer.h"
#include "catch.hpp"
#include <iostream>
#include <memory>
using namespace std;

TEST_CASE("Bomb test")
{
	shared_ptr<Game> G = make_shared<Game> ();
	Bomb_settings settings {2, 1, 1};
	
	SECTION("")
	{
		Bomb our_bomb(1, 1, settings, G, 1);
		G->add_bomb(1, 1, our_bomb);
		G->set_element(1, 1, 3);
		CHECK(G->get_element(1, 1) == 3);
		our_bomb.detonate();
		CHECK(G->get_element(1, 1) == 4);
		CHECK(G->get_element(1, 2) == 4);
		CHECK(G->get_element(2, 1) == 4);
		CHECK(G->get_element(1, 3) == 1);
	}
}