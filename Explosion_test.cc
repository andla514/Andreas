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
    shared_ptr<Matrix_Map> M = make_shared<Matrix_Map>();

    SECTION("Destructor and update()")
    {
		M->make_object(1, 1, make_unique<Explosion>(Explosion(1, 1, -1, false, M)));
		CHECK(M->is_explosion(1, 1));
		CHECK(dynamic_cast<Explosion&>(M->get_reference(1, 1)).get_was_box() == false);
		dynamic_cast<Explosion&>(M->get_reference(1, 1)).update();
    }

    CHECK(M->is_null(1, 1));

    SECTION("Time_left")
    {
		M->make_object(1, 2, make_unique<Explosion>(Explosion(1, 2, 1, false, M)));
		CHECK(round(dynamic_cast<Explosion&>(M->get_reference(1, 2)).time_left()) <= 1000);
		CHECK(round(dynamic_cast<Explosion&>(M->get_reference(1, 2)).time_left()) >= 950);
    }

    SECTION("Create Item") // To test, change the chance for item in function update() in file Explosion.cc
    {
     /* G->add_explosion(1, 2, make_unique<Explosion>(Explosion(1, 2, -1, true, G)));
      (G->get_explosion_reference(1, 2)).update();
      CHECK_NOTHROW(G->get_item_reference(1, 2)); */
    }
}