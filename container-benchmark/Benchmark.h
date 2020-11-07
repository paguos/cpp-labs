//
// Created by Pablo Osinaga on 07.11.20.
//

#ifndef CONTAINERS_BENCHMARK_BENCHMARK_H
#define CONTAINERS_BENCHMARK_BENCHMARK_H


#include <string>
#include <utility>
#include <vector>


class Benchmark {
private:
    std::string name;
public:
    Benchmark(std::string name) : name(std::move(name)) {};
    virtual int perform(int size){
        return -1;
    }
    std::string GetName() const {return name;}
};

struct BenchmarkResult {
    std::string name;
    int time;
public:
    bool operator<(BenchmarkResult const& br) const;
};

BenchmarkResult findBestBenchmark(std::vector<BenchmarkResult> benchmarkResults);

#endif //CONTAINERS_BENCHMARK_BENCHMARK_H
