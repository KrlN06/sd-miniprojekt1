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
#include "Random.h"

void Benchmark::run() {

    // Test all configured structure sizes
    for (int size : sizes) {

        // Repeat benchmark multiple times for stable average results
        for (int i = 0; i < 100; i++) {

            // Generate common random dataset
            DynamicArray<int> data = generateRandomData(size);

            // Create fresh empty structures----------------------------------
            DynamicArray<int> dynamicArray;
            SinglyLinkedList singlyLinkedList;
            DoublyLinkedList doublyLinkedList;
            //------------------------------------------------------------------

            // Fill all structures with identical data------------------------
            for (int i = 0; i < data.getSize(); i++) {
                dynamicArray.push_back(data[i]);
                singlyLinkedList.push_back(data[i]);
                doublyLinkedList.push_back(data[i]);
            }
            //------------------------------------------------------------------

            // Run benchmark operations--------------------------------------
            benchmarkDynamicArray(dynamicArray, data);
            benchmarkSinglyLinkedList(singlyLinkedList, data);
            benchmarkDoublyLinkedList(doublyLinkedList, data);
        }
        // Display average results for current structure size
        displayResults(size);
        
        // Clear collected results before testing next size
        dynamicArrayPushFrontResults.clear();
        dynamicArrayPushBackResults.clear();
        dynamicArrayInsertResults.clear();
        dynamicArrayPopFrontResults.clear();
        dynamicArrayPopBackResults.clear();
        dynamicArrayRemoveResults.clear();
        dynamicArrayFindResults.clear();

        singlyLinkedListPushFrontResults.clear();
        singlyLinkedListPushBackResults.clear();
        singlyLinkedListInsertResults.clear();
        singlyLinkedListPopFrontResults.clear();
        singlyLinkedListPopBackResults.clear();
        singlyLinkedListRemoveResults.clear();
        singlyLinkedListFindResults.clear();

        doublyLinkedListPushFrontResults.clear();
        doublyLinkedListPushBackResults.clear();
        doublyLinkedListInsertResults.clear();
        doublyLinkedListPopFrontResults.clear();
        doublyLinkedListPopBackResults.clear();
        doublyLinkedListRemoveResults.clear();
        doublyLinkedListFindResults.clear();


    }
}


//========================================================================
// DYNAMIC ARRAY BENCHMARKS
//========================================================================

void Benchmark::benchmarkDynamicArray(const DynamicArray<int>& originalArray, const DynamicArray<int>& data) {
    Timer timer;
    // Each operation is performed on a copy of the original structure
    // to ensure identical starting conditions for every measurement

    // Push front benchmark----------------------------------------------
    DynamicArray<int> pushFrontArray = originalArray;
    int pushFrontValue = Random::generateRandomInt(0, 99999);
    timer.start();
    pushFrontArray.push_front(pushFrontValue);
    timer.stop();
    dynamicArrayPushFrontResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Push back benchmark-----------------------------------------------
    DynamicArray<int> pushBackArray = originalArray;
    int pushBackValue = Random::generateRandomInt(0, 99999);
    timer.start();
    pushBackArray.push_back(pushBackValue);
    timer.stop();
    dynamicArrayPushBackResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Insert benchmark--------------------------------------------------
    DynamicArray<int> insertArray = originalArray;
    int insertValue = Random::generateRandomInt(0, 99999);
    int insertIndex = insertArray.getSize() / 2;
    timer.start();
    insertArray.insert(insertIndex, insertValue);
    timer.stop();
    dynamicArrayInsertResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Pop front benchmark-----------------------------------------------
    DynamicArray<int> popFrontArray = originalArray;
    timer.start();
    popFrontArray.pop_front();
    timer.stop();
    dynamicArrayPopFrontResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Pop back benchmark------------------------------------------------
    DynamicArray<int> popBackArray = originalArray;
    timer.start();
    popBackArray.pop_back();
    timer.stop();
    dynamicArrayPopBackResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Remove benchmark--------------------------------------------------
    DynamicArray<int> removeArray = originalArray;
    int removeIndex = removeArray.getSize() / 2;
    timer.start();
    removeArray.remove(removeIndex);
    timer.stop();
    dynamicArrayRemoveResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Find benchmark----------------------------------------------------
    DynamicArray<int> findArray = originalArray;
    int findIndex = Random::generateRandomInt(0, data.getSize() - 1);
    int valueToFind = data[findIndex];
    timer.start();
    int foundIndex = findArray.find(valueToFind);
    timer.stop();
    dynamicArrayFindResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------
}

//========================================================================
// SINGLY LINKED LIST BENCHMARKS
//========================================================================

void Benchmark::benchmarkSinglyLinkedList(const SinglyLinkedList &originalList, const DynamicArray<int> &data) {
    Timer timer;
    // Each operation is performed on a copy of the original structure
    // to ensure identical starting conditions for every measurement

    // Push front benchmark----------------------------------------------
    SinglyLinkedList pushFrontSinglyLinkedList = originalList;
    int pushFrontValue = Random::generateRandomInt(0, 99999);
    timer.start();
    pushFrontSinglyLinkedList.push_front(pushFrontValue);
    timer.stop();
    singlyLinkedListPushFrontResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Push back benchmark-----------------------------------------------
    SinglyLinkedList pushBackSinglyLinkedList = originalList;
    int pushBackValue = Random::generateRandomInt(0, 99999);
    timer.start();
    pushBackSinglyLinkedList.push_back(pushBackValue);
    timer.stop();
    singlyLinkedListPushBackResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Insert benchmark--------------------------------------------------
    SinglyLinkedList insertSinglyLinkedList = originalList;
    int insertValue = Random::generateRandomInt(0, 99999);
    int insertIndex = insertSinglyLinkedList.getSize() / 2;
    timer.start();
    insertSinglyLinkedList.insert(insertIndex, insertValue);
    timer.stop();
    singlyLinkedListInsertResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Pop front benchmark-----------------------------------------------
    SinglyLinkedList popFrontSinglyLinkedList = originalList;
    timer.start();
    popFrontSinglyLinkedList.pop_front();
    timer.stop();
    singlyLinkedListPopFrontResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Pop back benchmark-----------------------------------------------
    SinglyLinkedList popBackSinglyLinkedList = originalList;
    timer.start();
    popBackSinglyLinkedList.pop_back();
    timer.stop();
    singlyLinkedListPopBackResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Remove benchmark--------------------------------------------------
    SinglyLinkedList removeSinglyLinkedList = originalList;
    int removeIndex = removeSinglyLinkedList.getSize() / 2;
    timer.start();
    removeSinglyLinkedList.remove(removeIndex);
    timer.stop();
    singlyLinkedListRemoveResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Find benchmark----------------------------------------------------
    SinglyLinkedList findSinglyLinkedList = originalList;
    int findIndex = Random::generateRandomInt(0, data.getSize() - 1);
    int valueToFind = data[findIndex];
    timer.start();
    int foundIndex = findSinglyLinkedList.find(valueToFind);
    timer.stop();
    singlyLinkedListFindResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------
}


//========================================================================
// DOUBLY LINKED LIST BENCHMARKS
//========================================================================

void Benchmark::benchmarkDoublyLinkedList(const DoublyLinkedList &originalList, const DynamicArray<int> &data) {
    Timer timer;
    // Each operation is performed on a copy of the original structure
    // to ensure identical starting conditions for every measurement

    // Push front benchmark----------------------------------------------
    DoublyLinkedList pushFrontDoublyLinkedList = originalList;
    int pushFrontValue = Random::generateRandomInt(0, 99999);
    timer.start();
    pushFrontDoublyLinkedList.push_front(pushFrontValue);
    timer.stop();
    doublyLinkedListPushFrontResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Push back benchmark-----------------------------------------------
    DoublyLinkedList pushBackDoublyLinkedList = originalList;
    int pushBackValue = Random::generateRandomInt(0, 99999);
    timer.start();
    pushBackDoublyLinkedList.push_back(pushBackValue);
    timer.stop();
    doublyLinkedListPushBackResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Insert benchmark--------------------------------------------------
    DoublyLinkedList insertDoublyLinkedList = originalList;
    int insertValue = Random::generateRandomInt(0, 99999);
    int insertIndex = insertDoublyLinkedList.getSize() / 2;
    timer.start();
    insertDoublyLinkedList.insert(insertIndex, insertValue);
    timer.stop();
    doublyLinkedListInsertResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Pop front benchmark-----------------------------------------------
    DoublyLinkedList popFrontDoublyLinkedList = originalList;
    timer.start();
    popFrontDoublyLinkedList.pop_front();
    timer.stop();
    doublyLinkedListPopFrontResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Pop back benchmark------------------------------------------------
    DoublyLinkedList popBackDoublyLinkedList = originalList;
    timer.start();
    popBackDoublyLinkedList.pop_back();
    timer.stop();
    doublyLinkedListPopBackResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Remove benchmark--------------------------------------------------
    DoublyLinkedList removeDoublyLinkedList = originalList;
    int removeIndex = removeDoublyLinkedList.getSize() / 2;
    timer.start();
    removeDoublyLinkedList.remove(removeIndex);
    timer.stop();
    doublyLinkedListRemoveResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------

    // Find benchmark----------------------------------------------------
    DoublyLinkedList findDoublyLinkedList = originalList;
    int findIndex = Random::generateRandomInt(0, data.getSize() - 1);
    int valueToFind = data[findIndex];
    timer.start();
    int foundIndex = findDoublyLinkedList.find(valueToFind);
    timer.stop();
    doublyLinkedListFindResults.push_back(timer.getElapsedTime());
    //------------------------------------------------------------------



}




DynamicArray<int> Benchmark::generateRandomData(int size) {
    DynamicArray<int> data;

    // Fill the structure with random integer values
    for (int i = 0; i < size; i++) {
        data.push_back(Random::generateRandomInt(0, 99999));
    }

    return data;
}


long long Benchmark::calculateAverage(const DynamicArray<long long>& results) {
    // Sum all measured execution times stored in the results structure.
    // Then divide the total time by the number of measurements to get the average.

    if (results.isEmpty()) {
        return 0;
    }

    // Sum all measured times
    long long sum = 0;

    for (int i = 0; i < results.getSize(); i++) {
        sum += results[i];
    }

    // Return average execution time
    return sum / results.getSize();
}


void Benchmark::displayResults(int size) {
    // Display average benchmark results for current size
    std::cout << "Size: " << size << std::endl;
    // Dynamic Array results---------------------------------------------
    std::cout << "\nDynamic Array" << std::endl;
    std::cout << "push_front: " << calculateAverage(dynamicArrayPushFrontResults) << " ns" << std::endl;
    std::cout << "push_back: " << calculateAverage(dynamicArrayPushBackResults) << " ns" << std::endl;
    std::cout << "insert: " << calculateAverage(dynamicArrayInsertResults) << " ns" << std::endl;
    std::cout << "pop_front: " << calculateAverage(dynamicArrayPopFrontResults) << " ns" << std::endl;
    std::cout << "pop_back: " << calculateAverage(dynamicArrayPopBackResults) << " ns" << std::endl;
    std::cout << "remove: " << calculateAverage(dynamicArrayRemoveResults) << " ns" << std::endl;
    std::cout << "find: " << calculateAverage(dynamicArrayFindResults) << " ns" << std::endl;
    // Singly Linked List results----------------------------------------
    std::cout << "\nSingly Linked List" << std::endl;
    std::cout << "push_front: " << calculateAverage(singlyLinkedListPushFrontResults) << " ns" << std::endl;
    std::cout << "push_back: " << calculateAverage(singlyLinkedListPushBackResults) << " ns" << std::endl;
    std::cout << "insert: " << calculateAverage(singlyLinkedListInsertResults) << " ns" << std::endl;
    std::cout << "pop_front: " << calculateAverage(singlyLinkedListPopFrontResults) << " ns" << std::endl;
    std::cout << "pop_back: " << calculateAverage(singlyLinkedListPopBackResults) << " ns" << std::endl;
    std::cout << "remove: " << calculateAverage(singlyLinkedListRemoveResults) << " ns" << std::endl;
    std::cout << "find: " << calculateAverage(singlyLinkedListFindResults) << " ns" << std::endl;
    // Doubly Linked List results----------------------------------------
    std::cout << "\nDoubly Linked List" << std::endl;
    std::cout << "push_front: " << calculateAverage(doublyLinkedListPushFrontResults) << " ns" << std::endl;
    std::cout << "push_back: " << calculateAverage(doublyLinkedListPushBackResults) << " ns" << std::endl;
    std::cout << "insert: " << calculateAverage(doublyLinkedListInsertResults) << " ns" << std::endl;
    std::cout << "pop_front: " << calculateAverage(doublyLinkedListPopFrontResults) << " ns" << std::endl;
    std::cout << "pop_back: " << calculateAverage(doublyLinkedListPopBackResults) << " ns" << std::endl;
    std::cout << "remove: " << calculateAverage(doublyLinkedListRemoveResults) << " ns" << std::endl;
    std::cout << "find: " << calculateAverage(doublyLinkedListFindResults) << " ns" << std::endl;
    std::cout << "\n----------------------------------------" << std::endl;
}
