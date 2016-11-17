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
	G->add_characters(2, G);
	Bomb_settings settings {2, 1, 1};
	Bomb_settings s2 {2, -1, 1};
	
	SECTION("Detonate")
	{
		G->add_bomb(1, 1, Bomb {1, 1, settings, G, 1});
		G->set_element(1, 1, 3);
		CHECK(G->get_element(1, 1) == 3);
		(G->get_bomb_reference(1, 1)).detonate();
		CHECK(G->get_element(1, 1) == 4);
		CHECK(G->get_element(1, 2) == 4);
		CHECK(G->get_element(2, 1) == 4);
		CHECK(G->get_element(1, 3) == 1);
	}
	
	SECTION("Update")
	{
		G->add_bomb(1, 2, Bomb {1, 2, s2, G, 2});
		G->set_element(1, 2, 3);
		(G->get_bomb_reference(1, 2)).update();
		CHECK(G->get_element(1, 2) == 4);
		
	}
}