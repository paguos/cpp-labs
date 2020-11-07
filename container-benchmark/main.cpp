//
// Created by Pablo Osinaga on 07.11.20.
//

#include <stack>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "ContainerBenchmark.h"

using std::cout;
using std::endl;
using std::deque;
using std::list;
using std::vector;

int main() {
    cout << "Staring container benchmark ..." << endl;

    int const benchmarkSizes[4] = {10, 100, 1'000, 10'000};
    ContainerBenchmark<deque<int>> dequeBenchmark("deque");
    ContainerBenchmark<vector<int>> vectorBenchmark("vector");
    ContainerBenchmark<list<int>> listBenchmark("list");
    Benchmark *const benchmarks[3] = {&vectorBenchmark, &listBenchmark, &dequeBenchmark};

    for (int size: benchmarkSizes) {

        vector<BenchmarkResult> results;
        cout << "\nStarting benchmark for size: " << size << endl;

        for (Benchmark *b: benchmarks) {
            int time = b->perform(size);
            cout << b->GetName() << " time: " << time << endl;
            results.push_back(BenchmarkResult{b->GetName(), time});
        }

        BenchmarkResult bestResult = findBestBenchmark(results);
        cout << bestResult.name << " performs better!" << endl;
    }

    cout << "\nContainer benchmark completed!" << endl;

    return 0;
}

