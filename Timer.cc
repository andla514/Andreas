#include "Timer.h"
#include <chrono>

void Timer::stop() noexcept
{
    is_stopped = true;
    end_time = std::chrono::system_clock::now();
}
void Timer::restart() noexcept
{
    is_stopped = false;
    start_time = std::chrono::system_clock::now();
}
bool Timer::is_done() noexcept
{
    return elapsed_time() > duration;
}

int Timer::fraction_of_completion() noexcept
{
    return static_cast<int>(fraction * elapsed_time() / duration) % fraction;
}
double Timer::completion() noexcept
{
    double to_return{elapsed_time() / duration};
    if(to_return >= 1)
    {
        return 1;
    }
    return to_return;
}

double Timer::elapsed_time() noexcept
{
    if(!is_stopped)
    {
        end_time = std::chrono::system_clock::now();
    }
    std::chrono::duration<double> elapsed_seconds = end_time - start_time;
    return elapsed_seconds.count();
}

int Timer::time_left() noexcept
{
    if(is_done())
    {
        return 0;
    }
    else
    {
        return static_cast<int>(1000 * (duration - elapsed_time()));
    }
}