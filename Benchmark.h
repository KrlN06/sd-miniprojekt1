//
// Created by Karol Nalepa on 03/04/2026.
//

#ifndef PROJEKT_1_BENCHMARK_H
#define PROJEKT_1_BENCHMARK_H
#include "DynamicArray.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

// Stores raw timings and per-size averages for the full benchmark suite.
class Benchmark {
public:
    // Runs all benchmarks for all structures
    void run();
    const static int SIZE = 50;

private:
    // The same size schedule is reused for every measured operation.
    int sizes[SIZE] = {
        5000, 8000, 10000, 12000, 14000,
        16000, 18000, 20000, 24000, 28000,
        32000, 36000, 40000, 44000, 48000,
        52000, 56000, 60000, 64000, 68000,
        72000, 76000, 80000, 84000, 88000,
        92000, 96000, 100000, 104000, 108000,
        112000, 116000, 120000, 124000, 128000,
        132000, 136000, 140000, 144000, 148000,
        152000, 156000, 160000, 165000, 170000,
        175000, 180000, 185000, 190000, 200000
    };

    // Dynamic Array results
    DynamicArray<long long> dynamicArrayPushFrontResults;
    DynamicArray<long long> dynamicArrayPushBackResults;
    DynamicArray<long long> dynamicArrayInsertResults;

    DynamicArray<long long> dynamicArrayPopFrontResults;
    DynamicArray<long long> dynamicArrayPopBackResults;
    DynamicArray<long long> dynamicArrayRemoveResults;

    DynamicArray<long long> dynamicArrayFindResults;

    // Dynamic Array average results used for saving final benchmark data to CSV files
    // Each array stores one average time per tested structure size
    DynamicArray<long long> dynamicArrayPushFrontAverages;
    DynamicArray<long long> dynamicArrayPushBackAverages;
    DynamicArray<long long> dynamicArrayInsertAverages;

    DynamicArray<long long> dynamicArrayPopFrontAverages;
    DynamicArray<long long> dynamicArrayPopBackAverages;
    DynamicArray<long long> dynamicArrayRemoveAverages;

    DynamicArray<long long> dynamicArrayFindAverages;

    // Singly Linked List results
    DynamicArray<long long> singlyLinkedListPushFrontResults;
    DynamicArray<long long> singlyLinkedListPushBackResults;
    DynamicArray<long long> singlyLinkedListInsertResults;

    DynamicArray<long long> singlyLinkedListPopFrontResults;
    DynamicArray<long long> singlyLinkedListPopBackResults;
    DynamicArray<long long> singlyLinkedListRemoveResults;

    DynamicArray<long long> singlyLinkedListFindResults;

    // Singly Linked List average results used for saving final benchmark data to CSV files
    // Each array stores one average time per tested structure size
    DynamicArray<long long> singlyLinkedListPushFrontAverages;
    DynamicArray<long long> singlyLinkedListPushBackAverages;
    DynamicArray<long long> singlyLinkedListInsertAverages;

    DynamicArray<long long> singlyLinkedListPopFrontAverages;
    DynamicArray<long long> singlyLinkedListPopBackAverages;
    DynamicArray<long long> singlyLinkedListRemoveAverages;

    DynamicArray<long long> singlyLinkedListFindAverages;

    // Doubly Linked List results
    DynamicArray<long long> doublyLinkedListPushFrontResults;
    DynamicArray<long long> doublyLinkedListPushBackResults;
    DynamicArray<long long> doublyLinkedListInsertResults;

    DynamicArray<long long> doublyLinkedListPopFrontResults;
    DynamicArray<long long> doublyLinkedListPopBackResults;
    DynamicArray<long long> doublyLinkedListRemoveResults;

    DynamicArray<long long> doublyLinkedListFindResults;

    // Doubly Linked List average results used for saving final benchmark data to CSV files
    // Each array stores one average time per tested structure size
    DynamicArray<long long> doublyLinkedListPushFrontAverages;
    DynamicArray<long long> doublyLinkedListPushBackAverages;
    DynamicArray<long long> doublyLinkedListInsertAverages;

    DynamicArray<long long> doublyLinkedListPopFrontAverages;
    DynamicArray<long long> doublyLinkedListPopBackAverages;
    DynamicArray<long long> doublyLinkedListRemoveAverages;

    DynamicArray<long long> doublyLinkedListFindAverages;

    // Runs benchmark for dynamic array
    void benchmarkDynamicArray(const DynamicArray<int>& originalArray,
                               const DynamicArray<int>& data);

    // Runs benchmark for singly linked list
    void benchmarkSinglyLinkedList(const SinglyLinkedList& originalList,
                                   const DynamicArray<int>& data);

    // Runs benchmark for doubly linked list
    void benchmarkDoublyLinkedList(const DoublyLinkedList& originalList,
                                   const DynamicArray<int>& data);

    // Generates random data of given size
    DynamicArray<int> generateRandomData(int size);

    // Calculates average from collected results
    long long calculateAverage(const DynamicArray<long long>& results);

    // Displays results on screen
    void displayResults(int size);
};
#endif //PROJEKT_1_BENCHMARK_H
