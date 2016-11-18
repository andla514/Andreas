#include "Bomb.h"
#include "Game.h"
#include "Timer.h"
#include "Explosion.h"
#include "catch.hpp"
#include <iostream>
#include <memory>
using namespace std;

TEST_CASE("Bomb test")
{
	shared_ptr<Game> G = make_shared<Game> ();
	G->add_characters(2, G);
	Bomb_settings settings {2, 1, -1};
	
	
	SECTION("Detonate")
	{
		G->add_bomb(1, 1, Bomb {1, 1, settings, G, 1});
		G->set_element(1, 1, 3);
		CHECK(G->get_element(1, 1) == 3);
		G->add_explosion(2, 1, Explosion(2, 1, 3, false, G));
		(G->get_bomb_reference(1, 1)).update();
		(G->get_bomb_reference(1, 1)).detonate();
		CHECK(G->get_element(1, 1) == 4);
		CHECK(G->get_element(1, 2) == 4);
		(G->get_explosion_reference(1, 2)).update();
		CHECK(G->get_element(1, 2) == 0);
		CHECK(G->get_element(2, 1) == 4);
		CHECK(G->get_element(1, 3) == 1);
		// check that a new explosion with shorter timer is not created
		CHECK((G->get_explosion_reference(2, 1)).time_left() > 2000);
	}
}

TEST_CASE("Uppdate")
{
	shared_ptr<Game> G = make_shared<Game> ();
	G->add_characters(2, G);
	Bomb_settings s2 {2, -1, 1};
	
	G->add_bomb(1, 2, Bomb {1, 2, s2, G, 2});
	G->set_element(1, 2, 3);
	(G->get_bomb_reference(1, 2)).update();
	CHECK(G->get_element(1, 2) == 4);
}

TEST_CASE("Detonate bomb from explotion")
{
	shared_ptr<Game> G = make_shared<Game> ();
	G->add_characters(2, G);
	Bomb_settings s {2, 1, 1};

	G->add_bomb(1, 1, Bomb {1, 1, s, G, 2});
	G->add_bomb(1, 2, Bomb {1, 2, s, G, 2});
	(G->get_bomb_referemce(1, 1)).detonate();
	CHECK_THROWS(G->get_bomb_reference(1, 2));
}