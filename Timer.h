//
// Created by Karol Nalepa on 03/04/2026.
//

#ifndef PROJEKT_1_TIMER_H
#define PROJEKT_1_TIMER_H
#include <chrono>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;

public:
    Timer();
    ~Timer();
    long long getElapsedTime() const;
    void start();
    void stop();
};

#endif //PROJEKT_1_TIMER_H