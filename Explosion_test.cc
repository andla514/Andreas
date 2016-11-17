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
	
	G->add_explosion(1, 1, Explosion (1, 1, -1, false, G));
	G->set_element(1, 1, 4);
	CHECK(G->get_element(1, 1) == 4);
	(G->get_explosion_reference(1, 1)).update();
	}
	
	CHECK(G->get_element(1, 1) == 0);
	
	SECTION("Time_left")
	{
		G->add_explosion(1, 2, Explosion (1, 2, 1, false, G));
		CHECK(round((G->get_explosion_reference(1, 2)).time_left()) <=1000);
		CHECK(round((G->get_explosion_reference(1, 2)).time_left()) >=950);
	}
}