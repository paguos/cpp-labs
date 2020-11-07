//
// Created by Pablo Osinaga on 07.11.20.
//

#ifndef CONTAINERS_BENCHMARK_UTILS_H
#define CONTAINERS_BENCHMARK_UTILS_H

#include <chrono>

using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::steady_clock;
using std::chrono::system_clock;

template <typename Func>
long long TimeFunc(Func f){
    auto begin = steady_clock::now();
    f();
    auto end = steady_clock::now();

    return duration_cast<microseconds>(end-begin).count();
}

#endif //CONTAINERS_BENCHMARK_UTILS_H
