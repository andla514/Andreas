
#ifndef TIMER_H
#define TIMER_H
#include <chrono>

class Timer
{
    public:
    Timer(double seconds)
    :duration{seconds}
    {}

    // Stops the timer from counting
    void stop();
    // Restarts the entire counter with the same target duration
    void restart();
    // Returns if the timer has reached the target duration
    bool is_done();

    // Returns the elapsed time since the timer was started or restarted
    double elapsed_time();

    // Returns the time left in milliseconds until the target duration is reached
    int time_left();

    private:
    bool is_stopped{false};
    double duration{};
    std::chrono::time_point<std::chrono::system_clock> start_time{std::chrono::system_clock::now()};
    std::chrono::time_point<std::chrono::system_clock> end_time{};
};

#endif