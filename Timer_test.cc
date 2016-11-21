#include "Timer.h"
#include <thread>
#include "catch.hpp"
#include <iostream>
/*
TEST_CASE("Test Timer")
{
    Timer our_timer{4.5};
    CHECK_FALSE(our_timer.is_done());
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << our_timer.elapsed_time() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3500));
    our_timer.stop();

    double elapsed_time = our_timer.elapsed_time();
    std::cout << elapsed_time << std::endl;
    CHECK(our_timer.is_done());
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    CHECK(elapsed_time == our_timer.elapsed_time());

    our_timer.restart();
    CHECK_FALSE(our_timer.is_done());
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << our_timer.elapsed_time() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3500));
    our_timer.stop();

    elapsed_time = our_timer.elapsed_time();
    std::cout << elapsed_time << std::endl;
    CHECK(our_timer.is_done());
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    CHECK(elapsed_time == our_timer.elapsed_time());
}*/

TEST_CASE("Test completion")
{
    Timer our_timer{2, 8};
    while(!our_timer.is_done())
    {
        std::cout << "Completion: " << our_timer.completion() << std::endl;
        std::cout << "Fraction: " << our_timer.fraction_of_completion() << std::endl;
    }
}