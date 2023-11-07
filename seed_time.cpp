#include "seed_time.h"
#include <random>
std::mutex randSingleton::rand_mutex;


int randSingleton::Iint(int maxVal) {
//    int x;
//    std::lock_guard<std::mutex> lck(rand_mutex);
//    do {
//        x = rand();
//    } while (x >= (RAND_MAX - RAND_MAX % maxVal));
    static thread_local std::mt19937 generator(1000);
    std::uniform_int_distribution<int> distribution(0,maxVal - 1);
    return distribution(generator);
    // return x % maxVal;
}

int randSingleton::getInt(int maxVal) {
    return get().Iint(maxVal);
}

double randSingleton::getDouble(double maxVal) {
    return maxVal * (double)get().lazyIint() / (double)RAND_MAX;
}

bool randSingleton::getBool()
{
    return get().Iint(2);
}

int randSingleton::lazyIint()
{
    std::lock_guard<std::mutex> lck(rand_mutex);
    return rand();
}

std::vector<int> randSingleton::get_vec_of_unique_rand_ints(int maxVal, int size) {

    std::vector<int> intHolder;
    intHolder.reserve(size);
    intHolder.emplace_back(get().Iint(maxVal));
    for (int i = 1; i < size; i++) {
        intHolder.emplace_back(get().Iint(maxVal));

        for (int j = 0; j < i; ++j) {

            if (intHolder[j] == intHolder[i]) {
                j = -1;
                intHolder[i] = get().Iint(maxVal);
            }
        }

    }
    return intHolder;
}

randSingleton::randSingleton() {
        srand(time(NULL));
}


stopWatch::stopWatch()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    startTime = high_resolution_clock::now();
}

double stopWatch::doubleSecondsSinceStart()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - startTime;
    return ms_double.count() / 1000;
}



unsigned int stopWatch::IntSecondsSinceStart()
{

    return (unsigned int)(doubleSecondsSinceStart()+0.5f);
};

double stopWatch::double_millisecondsSinceStart()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - startTime;
    return ms_double.count();
}

void stopWatch::add_time(int time)
{
    startTime -= std::chrono::minutes(time);
}

double stopWatch::double_minutesSinceStart()
{
    return doubleSecondsSinceStart() / 60;
}

double stopWatch::double_hoursSinceStart()
{
    return double_minutesSinceStart() / 60;
};

unsigned int stopWatch::Int_millisecondsSinceStart()
{
    return (unsigned int)(double_millisecondsSinceStart()+0.5f);
}


