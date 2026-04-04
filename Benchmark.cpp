//
// Created by Karol Nalepa on 03/04/2026.
//

#include "Benchmark.h"
#include <cstdlib>
#include <iostream>

#include "DoublyLinkedList.h"
#include "DynamicArray.h"
#include "SinglyLinkedList.h"
#include "Timer.h"

void Benchmark::run() {

    // Loop through all tested structure sizes
    for (int size : sizes) {


        // Repeat benchmark multiple times for each size
        for (int i = 0; i < 10; i++) {

            // Generate common random dataset
            DynamicArray<int> data = generateRandomData(size);

            // Create fresh empty structures---------------------------------------------
            DynamicArray<int> dynamicArray;
            SinglyLinkedList singlyLinkedList;
            DoublyLinkedList doublyLinkedList;
            //---------------------------------------------------------------------------

            // Fill all structures with identical data-----------------------------------
            for (int i = 0; i < data.getSize(); i++) {
                dynamicArray.push_back(data[i]);
                singlyLinkedList.push_back(data[i]);
                doublyLinkedList.push_back(data[i]);
            }
            //---------------------------------------------------------------------------

            // Run benchmark operations---------------------------------------------------

            benchmarkDynamicArray(dynamicArray, data);

        }
        displayResults(size);
        dynamicArrayPushFrontResults.clear();
        dynamicArrayPushBackResults.clear();
    }
}


//========================================================================
// DYNAMIC ARRAY BENCHMARKS===============================================
//========================================================================

void Benchmark::benchmarkDynamicArray(const DynamicArray<int>& originalArray, const DynamicArray<int>& data) {

    Timer timer;

    // Push front benchmark--------------------------------------------------
    DynamicArray<int> pushFrontArray = originalArray;
    int pushFrontValue = rand() % 100000;
    timer.start();
    pushFrontArray.push_front(pushFrontValue);
    timer.stop();
    dynamicArrayPushFrontResults.push_back(timer.getElapsedTime());
    //----------------------------------------------------------------------

    // Push back benchmark--------------------------------------------------
    DynamicArray<int> pushBackArray = originalArray;
    int pushBackValue = rand() % 100000;
    timer.start();
    pushBackArray.push_back(pushBackValue);
    timer.stop();
    dynamicArrayPushBackResults.push_back(timer.getElapsedTime());
    //----------------------------------------------------------------------

    // Insert benchmark-----------------------------------------------------
    DynamicArray<int> insertArray = originalArray;
    int insertValue = rand() % 100000;
    int insertIndex = insertArray.getSize() / 2;
    timer.start();
    insertArray.insert(insertIndex, insertValue);
    timer.stop();
    dynamicArrayInsertResults.push_back(timer.getElapsedTime());
    //----------------------------------------------------------------------

    // Pop front benchmark--------------------------------------------------
    DynamicArray<int> popFrontArray = originalArray;
    timer.start();
    popFrontArray.pop_front();
    timer.stop();
    dynamicArrayPopFrontResults.push_back(timer.getElapsedTime());
    //----------------------------------------------------------------------

    // Pop back benchmark---------------------------------------------------
    DynamicArray<int> popBackArray = originalArray;
    timer.start();
    popBackArray.pop_back();
    timer.stop();
    dynamicArrayPopBackResults.push_back(timer.getElapsedTime());
    //----------------------------------------------------------------------

    // Remove benchmark-----------------------------------------------------
    DynamicArray<int> removeArray = originalArray;
    int removeIndex = removeArray.getSize() / 2;
    timer.start();
    removeArray.remove(removeIndex);
    timer.stop();
    dynamicArrayRemoveResults.push_back(timer.getElapsedTime());
    //----------------------------------------------------------------------

    // Find benchmark-------------------------------------------------------
    DynamicArray<int> findArray = originalArray;
    int findIndex = rand() % data.getSize();
    int valueToFind = data[findIndex];
    timer.start();
    int foundIndex = findArray.find(valueToFind);
    timer.stop();
    dynamicArrayFindResults.push_back(timer.getElapsedTime());
    //---------------------------------------------------------------------
}

//========================================================================
// SINGLY LINKED LIST BENCHMARK===========================================
//========================================================================

void Benchmark::benchmarkSinglyLinkedList(const SinglyLinkedList &originalList, const DynamicArray<int> &data) {


}


//========================================================================
// DOUBLY LINKED LIST BENCHMARK===========================================
//========================================================================

void Benchmark::benchmarkDoublyLinkedList(const DoublyLinkedList &originalList, const DynamicArray<int> &data) {


}




DynamicArray<int> Benchmark::generateRandomData(int size) {
    DynamicArray<int> data;

    for (int i = 0; i < size; i++) {
        data.push_back(rand() % 100000);
    }

    return data;
}


long long Benchmark::calculateAverage(const DynamicArray<long long>& results) {
    if (results.isEmpty()) {
        return 0;
    }

    long long sum = 0;

    for (int i = 0; i < results.getSize(); i++) {
        sum += results[i];
    }

    return sum / results.getSize();
}


void Benchmark::displayResults(int size) {
    std::cout << "Size: " << size << std::endl;
    std::cout << "\nDynamic Array" << std::endl;
    std::cout << "push_front: " << calculateAverage(dynamicArrayPushFrontResults) << " ns" << std::endl;
    std::cout << "push_back: " << calculateAverage(dynamicArrayPushBackResults) << " ns" << std::endl;
    std::cout << "insert: " << calculateAverage(dynamicArrayInsertResults) << " ns" << std::endl;
    std::cout << "pop_front: " << calculateAverage(dynamicArrayPopFrontResults) << " ns" << std::endl;
    std::cout << "pop_back: " << calculateAverage(dynamicArrayPopBackResults) << " ns" << std::endl;
    std::cout << "remove: " << calculateAverage(dynamicArrayRemoveResults) << " ns" << std::endl;
    std::cout << "find: " << calculateAverage(dynamicArrayFindResults) << " ns" << std::endl;
    std::cout << "\n----------------------------------------" << std::endl;
}




