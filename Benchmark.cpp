//
// Created by Karol Nalepa on 03/04/2026.
//

#include "Benchmark.h"

#include "DoublyLinkedList.h"
#include "DynamicArray.h"
#include "SinglyLinkedList.h"
#include "Timer.h"

void Benchmark::run() {
    int size;

    // Loop through all tested structure sizes
    for (int j = 0; j < 8; j++) {
        size = sizes[j];

        // Repeat benchmark multiple times for each size
        for (int i = 0; i < 10; i++) {

            // Generate common random dataset
            std::vector<int> data = generateRandomData(size);

            // Create fresh empty structures---------------------------------------------
            DynamicArray dynamicArray;
            SinglyLinkedList singlyLinkedList;
            DoublyLinkedList doublyLinkedList;
            //---------------------------------------------------------------------------

            // Fill all structures with identical data-----------------------------------
            for (int value : data) {
                dynamicArray.push_back(value);
                singlyLinkedList.push_back(value);
                doublyLinkedList.push_back(value);
            }
            //---------------------------------------------------------------------------

            // Run benchmark operations---------------------------------------------------

            benchmarkDynamicArray();


        }
    }
}

void Benchmark::benchmarkDynamicArray() {
    Timer timer;
    timer.start();

}