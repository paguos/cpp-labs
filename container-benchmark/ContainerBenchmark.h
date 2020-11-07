//
// Created by Pablo Osinaga on 07.11.20.
//

#ifndef CONTAINERS_BENCHMARK_CONTAINERBENCHMARK_H
#define CONTAINERS_BENCHMARK_CONTAINERBENCHMARK_H


#include <cstdlib>
#include <string>

#include "Benchmark.h"
#include "Utils.h"

using std::string;

template <class T>
class ContainerBenchmark : public Benchmark{
private:
    T container;
    void BuildContainer(int benchmarkSize){
        for (int i = 0; i < benchmarkSize; ++i) {
            int r = rand();
            bool inserted = false;
            for (auto it = begin(container); it != end(container); it++){
                if (*it > r){
                    container.insert(it, r);
                    inserted = true;
                    break;
                }
            }

            if (!inserted){
                container.push_back(r);
            }
        }
    };

public:
    ContainerBenchmark(string name) : Benchmark(name){
        container = {0};
    };
    virtual int perform(int benchmarkSize){
        int benchmarkTime = TimeFunc([&]() {BuildContainer(benchmarkSize);});
        return benchmarkTime;
    };
};

#endif //CONTAINERS_BENCHMARK_CONTAINERBENCHMARK_H
