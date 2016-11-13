#include "Timer.h"

void Timer::stop()
{
    is_stopped = true;
    end_time = std::chrono::system_clock::now();
}
void Timer::restart()
{
    is_stopped = false;
    start_time = std::chrono::system_clock::now();
}
bool Timer::is_done()
{
    return elapsed_time() > duration;
}
double Timer::elapsed_time()
{
    if(!is_stopped)
    {
        end_time = std::chrono::system_clock::now();
    }
    std::chrono::duration<double> elapsed_seconds = end_time - start_time;
    return elapsed_seconds.count();
}

int Timer::time_left()
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