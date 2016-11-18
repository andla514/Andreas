#include "Explosion.h"
#include "Timer.h"
#include "Game.h"
#include "Item.h"
#include "catch.hpp"
#include <iostream>
#include <memory>
using namespace std;

TEST_CASE("Explosion test")
{
    std::shared_ptr<Game> G = make_shared<Game>();

    SECTION("Destructor and update()")
    {
		G->add_explosion(1, 1, make_unique<Explosion>(Explosion(1, 1, -1, false, G)));
		G->set_element(1, 1, 4);
		CHECK(G->get_element(1, 1) == 4);
		CHECK((G->get_explosion_reference(1, 1)).get_was_box() == false);
		(G->get_explosion_reference(1, 1)).update();
    }

    CHECK(G->get_element(1, 1) == 0);

    SECTION("Time_left")
    {
		G->add_explosion(1, 2, make_unique<Explosion>(Explosion(1, 2, 1, false, G)));
		CHECK(round((G->get_explosion_reference(1, 2)).time_left()) <= 1000);
		CHECK(round((G->get_explosion_reference(1, 2)).time_left()) >= 950);
    }

    SECTION("Create Item") // To test, change the chance for item in function update() in file Explosion.cc
    {
     /* G->add_explosion(1, 2, make_unique<Explosion>(Explosion(1, 2, -1, true, G)));
      (G->get_explosion_reference(1, 2)).update();
      CHECK_NOTHROW(G->get_item_reference(1, 2)); */
    }
}