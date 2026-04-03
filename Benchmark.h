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
    std::vector<long long> dynamicArrayPushFrontResults;
    std::vector<long long> dynamicArrayPushBackResults;
    std::vector<long long> dynamicArrayInsertResults;

    std::vector<long long> dynamicArrayPopFrontResults;
    std::vector<long long> dynamicArrayPopBackResults;
    std::vector<long long> dynamicArrayRemoveResults;

    std::vector<long long> dynamicArrayFindResults;

    // Singly Linked List results
    std::vector<long long> singlyLinkedListPushFrontResults;
    std::vector<long long> singlyLinkedListPushBackResults;
    std::vector<long long> singlyLinkedListInsertResults;

    std::vector<long long> singlyLinkedListPopFrontResults;
    std::vector<long long> singlyLinkedListPopBackResults;
    std::vector<long long> singlyLinkedListRemoveResults;

    std::vector<long long> singlyLinkedListFindResults;

    // Doubly Linked List results
    std::vector<long long> doublyLinkedListPushFrontResults;
    std::vector<long long> doublyLinkedListPushBackResults;
    std::vector<long long> doublyLinkedListInsertResults;

    std::vector<long long> doublyLinkedListPopFrontResults;
    std::vector<long long> doublyLinkedListPopBackResults;
    std::vector<long long> doublyLinkedListRemoveResults;

    std::vector<long long> doublyLinkedListFindResults;

    // Runs benchmark for dynamic array
    void benchmarkDynamicArray(const DynamicArray& originalArray,
                               const std::vector<int>& data);

    // Runs benchmark for singly linked list
    void benchmarkSinglyLinkedList(const SinglyLinkedList& originalList,
                                   const std::vector<int>& data);

    // Runs benchmark for doubly linked list
    void benchmarkDoublyLinkedList(const DoublyLinkedList& originalList,
                                   const std::vector<int>& data);

    // Generates random data of given size
    std::vector<int> generateRandomData(int size);

    // Calculates average from collected results
    long long calculateAverage(const std::vector<long long>& results);

    // Displays results on screen
    void displayResults();
};
#endif //PROJEKT_1_BENCHMARK_H