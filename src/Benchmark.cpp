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
#include "BenchmarkSaver.h"


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

        // Store averages for CSV saving
        dynamicArrayPushFrontAverages.push_back(calculateAverage(dynamicArrayPushFrontResults));
        dynamicArrayPushBackAverages.push_back(calculateAverage(dynamicArrayPushBackResults));
        dynamicArrayInsertAverages.push_back(calculateAverage(dynamicArrayInsertResults));
        dynamicArrayPopFrontAverages.push_back(calculateAverage(dynamicArrayPopFrontResults));
        dynamicArrayPopBackAverages.push_back(calculateAverage(dynamicArrayPopBackResults));
        dynamicArrayRemoveAverages.push_back(calculateAverage(dynamicArrayRemoveResults));
        dynamicArrayFindAverages.push_back(calculateAverage(dynamicArrayFindResults));

        singlyLinkedListPushFrontAverages.push_back(calculateAverage(singlyLinkedListPushFrontResults));
        singlyLinkedListPushBackAverages.push_back(calculateAverage(singlyLinkedListPushBackResults));
        singlyLinkedListInsertAverages.push_back(calculateAverage(singlyLinkedListInsertResults));
        singlyLinkedListPopFrontAverages.push_back(calculateAverage(singlyLinkedListPopFrontResults));
        singlyLinkedListPopBackAverages.push_back(calculateAverage(singlyLinkedListPopBackResults));
        singlyLinkedListRemoveAverages.push_back(calculateAverage(singlyLinkedListRemoveResults));
        singlyLinkedListFindAverages.push_back(calculateAverage(singlyLinkedListFindResults));

        doublyLinkedListPushFrontAverages.push_back(calculateAverage(doublyLinkedListPushFrontResults));
        doublyLinkedListPushBackAverages.push_back(calculateAverage(doublyLinkedListPushBackResults));
        doublyLinkedListInsertAverages.push_back(calculateAverage(doublyLinkedListInsertResults));
        doublyLinkedListPopFrontAverages.push_back(calculateAverage(doublyLinkedListPopFrontResults));
        doublyLinkedListPopBackAverages.push_back(calculateAverage(doublyLinkedListPopBackResults));
        doublyLinkedListRemoveAverages.push_back(calculateAverage(doublyLinkedListRemoveResults));
        doublyLinkedListFindAverages.push_back(calculateAverage(doublyLinkedListFindResults));

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

    // Export one CSV file per operation after all averages are ready.
    BenchmarkSaver::saveOperationResults(
        "push_front.csv",
        sizes,
        dynamicArrayPushFrontAverages,
        singlyLinkedListPushFrontAverages,
        doublyLinkedListPushFrontAverages,
        SIZE
    );

    BenchmarkSaver::saveOperationResults(
        "push_back.csv",
        sizes,
        dynamicArrayPushBackAverages,
        singlyLinkedListPushBackAverages,
        doublyLinkedListPushBackAverages,
        SIZE
    );

    BenchmarkSaver::saveOperationResults(
        "insert.csv",
        sizes,
        dynamicArrayInsertAverages,
        singlyLinkedListInsertAverages,
        doublyLinkedListInsertAverages,
        SIZE
    );

    BenchmarkSaver::saveOperationResults(
        "pop_front.csv",
        sizes,
        dynamicArrayPopFrontAverages,
        singlyLinkedListPopFrontAverages,
        doublyLinkedListPopFrontAverages,
        SIZE
    );

    BenchmarkSaver::saveOperationResults(
        "pop_back.csv",
        sizes,
        dynamicArrayPopBackAverages,
        singlyLinkedListPopBackAverages,
        doublyLinkedListPopBackAverages,
        SIZE
    );

    BenchmarkSaver::saveOperationResults(
        "remove.csv",
        sizes,
        dynamicArrayRemoveAverages,
        singlyLinkedListRemoveAverages,
        doublyLinkedListRemoveAverages,
        SIZE
    );

    BenchmarkSaver::saveOperationResults(
        "find.csv",
        sizes,
        dynamicArrayFindAverages,
        singlyLinkedListFindAverages,
        doublyLinkedListFindAverages,
        SIZE
    );
}


//========================================================================
// DYNAMIC ARRAY BENCHMARKS
//========================================================================

void Benchmark::benchmarkDynamicArray(const DynamicArray<int>& originalArray, const DynamicArray<int>& data) {
    Timer timer;
    const int repetitions = 1;
    // Each operation is performed on a copy of the original structure
    // to ensure identical starting conditions for every measurement

    // Push front benchmark----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DynamicArray<int> pushFrontArray = originalArray;
            int pushFrontValue = Random::generateRandomInt(0, 99999);
            timer.start();
            pushFrontArray.push_front(pushFrontValue);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        dynamicArrayPushFrontResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Push back benchmark-----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DynamicArray<int> pushBackArray = originalArray;
            int pushBackValue = Random::generateRandomInt(0, 99999);
            timer.start();
            pushBackArray.push_back(pushBackValue);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        dynamicArrayPushBackResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Insert benchmark--------------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DynamicArray<int> insertArray = originalArray;
            int insertValue = Random::generateRandomInt(0, 99999);
            int insertIndex = insertArray.getSize() / 2;
            timer.start();
            insertArray.insert(insertIndex, insertValue);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        dynamicArrayInsertResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Pop front benchmark-----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DynamicArray<int> popFrontArray = originalArray;
            timer.start();
            popFrontArray.pop_front();
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        dynamicArrayPopFrontResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Pop back benchmark------------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DynamicArray<int> popBackArray = originalArray;
            timer.start();
            popBackArray.pop_back();
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        dynamicArrayPopBackResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Remove benchmark--------------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DynamicArray<int> removeArray = originalArray;
            int removeIndex = Random::generateRandomInt(0, originalArray.getSize() - 1);
            timer.start();
            removeArray.remove(removeIndex);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        dynamicArrayRemoveResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Find benchmark----------------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DynamicArray<int> findArray = originalArray;
            int findIndex = Random::generateRandomInt(0, data.getSize() - 1);
            int valueToFind = data[findIndex];
            timer.start();
            int foundIndex = findArray.find(valueToFind);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        dynamicArrayFindResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------
}

//========================================================================
// SINGLY LINKED LIST BENCHMARKS
//========================================================================

void Benchmark::benchmarkSinglyLinkedList(const SinglyLinkedList &originalList, const DynamicArray<int> &data) {
    Timer timer;
    const int repetitions = 1;
    // Each operation is performed on a copy of the original structure
    // to ensure identical starting conditions for every measurement

    // Push front benchmark----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            SinglyLinkedList pushFrontSinglyLinkedList = originalList;
            int pushFrontValue = Random::generateRandomInt(0, 99999);
            timer.start();
            pushFrontSinglyLinkedList.push_front(pushFrontValue);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        singlyLinkedListPushFrontResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Push back benchmark-----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            SinglyLinkedList pushBackSinglyLinkedList = originalList;
            int pushBackValue = Random::generateRandomInt(0, 99999);
            timer.start();
            pushBackSinglyLinkedList.push_back(pushBackValue);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        singlyLinkedListPushBackResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Insert benchmark--------------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            SinglyLinkedList insertSinglyLinkedList = originalList;
            int insertValue = Random::generateRandomInt(0, 99999);
            int insertIndex = insertSinglyLinkedList.getSize() / 2;
            timer.start();
            insertSinglyLinkedList.insert(insertIndex, insertValue);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        singlyLinkedListInsertResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Pop front benchmark-----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            SinglyLinkedList popFrontSinglyLinkedList = originalList;
            timer.start();
            popFrontSinglyLinkedList.pop_front();
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        singlyLinkedListPopFrontResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Pop back benchmark-----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            SinglyLinkedList popBackSinglyLinkedList = originalList;
            timer.start();
            popBackSinglyLinkedList.pop_back();
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        singlyLinkedListPopBackResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Remove benchmark--------------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            SinglyLinkedList removeSinglyLinkedList = originalList;
            int removeIndex = Random::generateRandomInt(0, removeSinglyLinkedList.getSize() - 1);
            timer.start();
            removeSinglyLinkedList.remove(removeIndex);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        singlyLinkedListRemoveResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Find benchmark----------------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            SinglyLinkedList findSinglyLinkedList = originalList;
            int findIndex = Random::generateRandomInt(0, data.getSize() - 1);
            int valueToFind = data[findIndex];
            timer.start();
            int foundIndex = findSinglyLinkedList.find(valueToFind);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        singlyLinkedListFindResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------
}


//========================================================================
// DOUBLY LINKED LIST BENCHMARKS
//========================================================================

void Benchmark::benchmarkDoublyLinkedList(const DoublyLinkedList &originalList, const DynamicArray<int> &data) {
    Timer timer;
    const int repetitions = 1;
    // Each operation is performed on a copy of the original structure
    // to ensure identical starting conditions for every measurement

    // Push front benchmark----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DoublyLinkedList pushFrontDoublyLinkedList = originalList;
            int pushFrontValue = Random::generateRandomInt(0, 99999);
            timer.start();
            pushFrontDoublyLinkedList.push_front(pushFrontValue);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        doublyLinkedListPushFrontResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Push back benchmark-----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DoublyLinkedList pushBackDoublyLinkedList = originalList;
            int pushBackValue = Random::generateRandomInt(0, 99999);
            timer.start();
            pushBackDoublyLinkedList.push_back(pushBackValue);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        doublyLinkedListPushBackResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Insert benchmark--------------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DoublyLinkedList insertDoublyLinkedList = originalList;
            int insertValue = Random::generateRandomInt(0, 99999);
            int insertIndex = insertDoublyLinkedList.getSize() / 2;
            timer.start();
            insertDoublyLinkedList.insert(insertIndex, insertValue);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        doublyLinkedListInsertResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Pop front benchmark-----------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DoublyLinkedList popFrontDoublyLinkedList = originalList;
            timer.start();
            popFrontDoublyLinkedList.pop_front();
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        doublyLinkedListPopFrontResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Pop back benchmark------------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DoublyLinkedList popBackDoublyLinkedList = originalList;
            timer.start();
            popBackDoublyLinkedList.pop_back();
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        doublyLinkedListPopBackResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Remove benchmark--------------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DoublyLinkedList removeDoublyLinkedList = originalList;
            int removeIndex = Random::generateRandomInt(0, removeDoublyLinkedList.getSize() - 1);
            timer.start();
            removeDoublyLinkedList.remove(removeIndex);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        doublyLinkedListRemoveResults.push_back(totalTime / repetitions);
    }
    //------------------------------------------------------------------

    // Find benchmark----------------------------------------------------
    {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            DoublyLinkedList findDoublyLinkedList = originalList;
            int findIndex = Random::generateRandomInt(0, data.getSize() - 1);
            int valueToFind = data[findIndex];
            timer.start();
            int foundIndex = findDoublyLinkedList.find(valueToFind);
            timer.stop();
            totalTime += timer.getElapsedTime();
        }
        doublyLinkedListFindResults.push_back(totalTime / repetitions);
    }
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
