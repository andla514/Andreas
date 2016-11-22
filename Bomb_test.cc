#include "Bomb.h"
#include "Game.h"
#include "Matrix_Map.h"
#include "Timer.h"
#include "Explosion.h"
#include "Item.h"
#include "catch.hpp"
#include <iostream>
#include <memory>
using namespace std;

TEST_CASE("Bomb test")
{
    shared_ptr<Matrix_Map> M = make_shared<Matrix_Map>();
	Character* C = new Character{};
    Bomb_settings settings{2, 1, -1};

    SECTION("Detonate")
    {
	M->make_object(1, 1, make_unique<Bomb>(Bomb{1, 1, settings, M, C}));
	CHECK(M->is_bomb(1, 1));
	M->make_object(2, 1, make_unique<Explosion>(Explosion(2, 1, 3, false, M)));
	dynamic_cast<Bomb&>(M->get_reference(1, 1)).update();
	dynamic_cast<Bomb&>(M->get_reference(1, 1)).detonate();

	CHECK(M->is_explosion(1, 1));
	CHECK(M->is_explosion(1, 2));
	dynamic_cast<Explosion&>(M->get_reference(1, 2)).update();
	CHECK(M->is_null(1, 2));
	CHECK(M->is_explosion(2, 1));
	CHECK(M->is_box(1, 3)); // Only work if a box has been created here. This is randomized
	// check that a new explosion with shorter timer is not created
	CHECK(dynamic_cast<Explosion&>(M->get_reference(2, 1)).time_left() > 2000);
		cout << "h1";

    }
}

TEST_CASE("Update")
{
    Character* C = new Character{};
	shared_ptr<Matrix_Map> M = make_shared<Matrix_Map>();
    Bomb_settings s2{2, -1, 1};

    M->make_object(1, 2, make_unique<Bomb>(Bomb{1, 2, s2, M, C}));
    dynamic_cast<Bomb&>(M->get_reference(1, 2)).update();
    CHECK(M->is_explosion(1, 2));
}

TEST_CASE("Detonate bomb from explosion")
{
    Character* C = new Character{};
    shared_ptr<Matrix_Map> M = make_shared<Matrix_Map>();
    Bomb_settings s{2, 1, 1};
	Bomb_settings s2{2, -1, 1};

    M->make_object(1, 1, make_unique<Bomb>(Bomb{1, 1, s2, M, C}));    
    M->make_object(1, 2, make_unique<Bomb>(Bomb{1, 2, s, M, C}));
    dynamic_cast<Bomb&>(M->get_reference(1, 1)).detonate();
    CHECK(M->is_explosion(1, 2));
}

TEST_CASE("Detonate and destroy item")
{
	Character* C = new Character{};
    shared_ptr<Matrix_Map> M = make_shared<Matrix_Map>();
    Bomb_settings s{2, 1, 1};

	M->make_object(1, 1, make_unique<Bomb>(Bomb{1, 1, s, M, C}));    
	M->make_object(1, 2, make_unique<Item_Inc_Bombs>(1, 2));
	dynamic_cast<Bomb&>(M->get_reference(1, 1)).detonate();
	CHECK(M->is_explosion(1, 2));
}