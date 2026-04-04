//
// Created by Karol Nalepa on 03/04/2026.
//

#include "Benchmark.h"
#include <cstdlib>
#include <vector>
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

void Benchmark::benchmarkDynamicArray(const DynamicArray<int>& originalArray, const DynamicArray<int>& data) {

    Timer timer;

    DynamicArray<int> pushFrontArray = originalArray;
    int pushFrontValue = rand() % 100000;
    timer.start();
    pushFrontArray.push_front(pushFrontValue);
    timer.stop();
    dynamicArrayPushFrontResults.push_back(timer.getElapsedTime());

    DynamicArray<int> pushBackArray = originalArray;
    int pushBackValue = rand() % 100000;
    timer.start();
    pushBackArray.push_back(pushBackValue);
    timer.stop();
    dynamicArrayPushBackResults.push_back(timer.getElapsedTime());

    DynamicArray<int> insertArray = originalArray;
    int insertValue = rand() % 100000;
    int insertIndex = insertArray.getSize() / 2;
    timer.start();
    insertArray.insert(insertIndex, insertValue);
    timer.stop();
    dynamicArrayInsertResults.push_back(timer.getElapsedTime());
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
    std::cout << "\n----------------------------------------" << std::endl;
}




