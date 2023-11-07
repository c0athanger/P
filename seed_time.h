#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <mutex>
#include <chrono>
class randSingleton {
public:
    randSingleton(const randSingleton&) = delete;
    static randSingleton& get() {
        static randSingleton s_Instance;
        return s_Instance;
    }

    static std::vector<int> get_vec_of_unique_rand_ints(int maxVal, int size);

    static int getInt(int maxVal);
    static double getDouble(double maxVal);

    static bool getBool();

private:
    int lazyIint();
    int Iint(int maxVal);
    randSingleton();
    static std::mutex rand_mutex;


};

class stopWatch
{
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

public:
    stopWatch();
    unsigned int IntSecondsSinceStart();
    double doubleSecondsSinceStart();

    unsigned int Int_millisecondsSinceStart();
    double double_millisecondsSinceStart();
    void add_time(int time);
    double double_minutesSinceStart();
    double double_hoursSinceStart();

};

