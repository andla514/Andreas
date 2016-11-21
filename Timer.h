
#ifndef TIMER_H
#define TIMER_H
#include <chrono>

class Timer
{
    public:
    Timer(double seconds, int fraction = 1)
    :duration{seconds}, fraction{fraction}
    {}

    // Stops the timer from counting
    void stop() noexcept;
    // Restarts the entire counter with the same target duration
    void restart() noexcept;
    // Returns if the timer has reached the target duration
    bool is_done() noexcept;

    // Returns how many whole parts of fraction has passed (using modulus)
    int fraction_of_completion() noexcept;
    // Returns how completed the timer is. 0 at start and 1 at end
    double completion() noexcept;

    // Returns the elapsed time since the timer was started or restarted
    double elapsed_time() noexcept;
    // Returns the time left in milliseconds until the target duration is reached
    int time_left() noexcept;

    private:
    bool is_stopped{false};
    double duration{};
    int fraction{};
    std::chrono::time_point<std::chrono::system_clock> start_time{std::chrono::system_clock::now()};
    std::chrono::time_point<std::chrono::system_clock> end_time{};
};

#endif