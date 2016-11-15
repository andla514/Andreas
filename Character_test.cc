#include <memory>
#include "Character.h"
#include "catch.hpp"
#include <iostream>
#define WINVER 0x0500
#include <windows.h>

TEST_CASE("test of creating and move character")
{
    std::shared_ptr<Game> game_ptr = std::make_shared<Game>();
    Character our_character(game_ptr,1);
    CHECK(our_character.get_col() == 1);
    CHECK(our_character.get_row() == 1);

    INPUT input;
    //Input type keyboard
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    SECTION("Move down")
    {
    input.ki.wVk = 0x53; //"S"
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));

    our_character.update();

    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));

    CHECK(our_character.get_col() == 1);
    CHECK(our_character.get_row() == 2);
    }

   SECTION("Move right")
    {
    input.ki.wVk = 0x44; //"D"
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));

    our_character.update();

    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));

    CHECK(our_character.get_col() == 2);
    CHECK(our_character.get_row() == 1);

    our_character.update();

    input.ki.wVk = 0x44;//"D"
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));

    our_character.update();

    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));

    CHECK(our_character.get_col() == 3);
    CHECK(our_character.get_row() == 1);



    }

    SECTION("move against the wall")
    {
    game_ptr->set_element(0, 0, 5);
    game_ptr->set_element(0, 1, 5);
    game_ptr->set_element(1, 0, 5);
    input.ki.wVk = 0x41; //"A"
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));

    our_character.update();

    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));

    CHECK(our_character.get_col() == 1);
    CHECK(our_character.get_row() == 1);
    }
}

TEST_CASE("Test of creating another playerwith diffrent keybindings")
{
    std::shared_ptr<Game> game_ptr = std::make_shared<Game>();
    Character our_character(game_ptr,2);

    CHECK(our_character.get_col() == 24);
    CHECK(our_character.get_row() == 18);


    INPUT input;
    //Input type keyboard
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    SECTION("Move up")
    {
    input.ki.wVk = 0x26; // "UP-arrow"
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));

    our_character.update();

    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
    
    CHECK(our_character.get_col() == 24);
    CHECK(our_character.get_row() == 17);
    }

    SECTION("Move left")
    {
    input.ki.wVk = 0x25; //"Left-arrow"
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));

    our_character.update();

    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));

    CHECK(our_character.get_col() == 23);
    CHECK(our_character.get_row() == 18);
    }

}