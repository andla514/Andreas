#include "Explosion.h"
#include "Timer.h"
#include "Game.h"
#include "catch.hpp"
#include <iostream>
#include <memory>
using namespace std;

TEST_CASE("Explosion test")
{
	std::shared_ptr<Game> G = make_shared<Game> ();
    
	SECTION("Destructor and update()")
	{
	Explosion our_explosion(1, 1, 0, false, G);
	G->add_explosion(1, 1, our_explosion);
	G->set_element(1, 1, 4);
	CHECK(G->get_element(1, 1) == 4);
	our_explosion.update();
	}
	
	CHECK(G->get_element(1, 1) == 0);
}