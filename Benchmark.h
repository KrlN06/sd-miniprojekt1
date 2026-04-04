//
// Created by Karol Nalepa on 03/04/2026.
//

#ifndef PROJEKT_1_BENCHMARK_H
#define PROJEKT_1_BENCHMARK_H
#include "DynamicArray.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include <vector>

class Benchmark {
public:
    // Runs all benchmarks for all structures
    void run();

private:
    int sizes[8] = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};

    // Dynamic Array results
    DynamicArray<long long> dynamicArrayPushFrontResults;
    DynamicArray<long long> dynamicArrayPushBackResults;
    DynamicArray<long long> dynamicArrayInsertResults;

    DynamicArray<long long> dynamicArrayPopFrontResults;
    DynamicArray<long long> dynamicArrayPopBackResults;
    DynamicArray<long long> dynamicArrayRemoveResults;

    DynamicArray<long long> dynamicArrayFindResults;

    // Singly Linked List results
    DynamicArray<long long> singlyLinkedListPushFrontResults;
    DynamicArray<long long> singlyLinkedListPushBackResults;
    DynamicArray<long long> singlyLinkedListInsertResults;

    DynamicArray<long long> singlyLinkedListPopFrontResults;
    DynamicArray<long long> singlyLinkedListPopBackResults;
    DynamicArray<long long> singlyLinkedListRemoveResults;

    DynamicArray<long long> singlyLinkedListFindResults;

    // Doubly Linked List results
    DynamicArray<long long> doublyLinkedListPushFrontResults;
    DynamicArray<long long> doublyLinkedListPushBackResults;
    DynamicArray<long long> doublyLinkedListInsertResults;

    DynamicArray<long long> doublyLinkedListPopFrontResults;
    DynamicArray<long long> doublyLinkedListPopBackResults;
    DynamicArray<long long> doublyLinkedListRemoveResults;

    DynamicArray<long long> doublyLinkedListFindResults;

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