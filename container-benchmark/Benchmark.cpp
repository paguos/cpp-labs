//
// Created by Pablo Osinaga on 07.11.20.
//

#include <algorithm>

#include "Benchmark.h"

bool BenchmarkResult::operator<(const BenchmarkResult &br) const {
    return time < br.time;
}

BenchmarkResult findBestBenchmark(std::vector<BenchmarkResult> benchmarkResults) {
    BenchmarkResult bestResult = benchmarkResults[0];

    for (int i = 1; i < benchmarkResults.size(); ++i) {
        BenchmarkResult result = benchmarkResults[i];
        if(result < bestResult){
            bestResult = result;
        }
    }
    return bestResult;
}


