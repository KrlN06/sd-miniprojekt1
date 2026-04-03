//
// Created by Karol Nalepa on 03/04/2026.
//

#ifndef PROJEKT_1_BENCHMARK_H
#define PROJEKT_1_BENCHMARK_H


class Benchmark {
public:
    // Runs all benchmarks for all structures
    void run();

private:
    // Runs benchmark for dynamic array
    void benchmarkDynamicArray();

    // Runs benchmark for singly linked list
    void benchmarkSinglyLinkedList();

    // Runs benchmark for doubly linked list
    void benchmarkDoublyLinkedList();

    // Runs all operations for selected structure size
    void runTestsForSize(int size);

    // Generates random data of given size
    std::vector<int> generateRandomData(int size);

    // Calculates average from collected results
    long long calculateAverage(const std::vector<long long>& results);

    // Displays results on screen
    void displayResults();

    // Benchmarks add at beginning
    long long benchmarkAddBeginning(int size);

    // Benchmarks add at end
    long long benchmarkAddEnd(int size);

    // Benchmarks add at random position
    long long benchmarkAddRandom(int size);

    // Benchmarks remove from beginning
    long long benchmarkRemoveBeginning(int size);

    // Benchmarks remove from end
    long long benchmarkRemoveEnd(int size);

    // Benchmarks remove from random position
    long long benchmarkRemoveRandom(int size);

    // Benchmarks find operation
    long long benchmarkFind(int size);
};

#endif //PROJEKT_1_BENCHMARK_H