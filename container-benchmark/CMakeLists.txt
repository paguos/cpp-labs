cmake_minimum_required(VERSION 3.17)
project(container-benchmark)

set(CMAKE_CXX_STANDARD 17)

add_executable(container-benchmark main.cpp Benchmark.cpp Benchmark.h ContainerBenchmark.h Utils.h)