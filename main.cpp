#include "DynamicArray.h"
#include "SinglyLinkedList.h"
#include  "DoublyLinkedList.h"
#include "Timer.h"
#include <iostream>



int main() {
    const int sizes[8] = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};
    const int repetitions = 10;

    Timer timer;

    for (int s = 0; s < 8; s++) {
        int n = sizes[s];

        long long totalPushBack = 0;
        long long totalInsertMiddle = 0;
        long long totalRemoveMiddle = 0;
        long long totalFind = 0;

        for (int r = 0; r < repetitions; r++) {
            DoublyLinkedList list;

            for (int i = 0; i < n; i++) {
                list.push_back(rand());
            }

            timer.start();

            for (int i = 0; i < 1000; i++) {
                list.push_back(rand());
            }

            timer.stop();
            totalPushBack += timer.getElapsedTime();

            timer.start();

            for (int i = 0; i < 1000; i++) {
                list.insert(list.getSize() / 2, rand());
            }

            timer.stop();
            totalInsertMiddle += timer.getElapsedTime();

            timer.start();

            for (int i = 0; i < 1000; i++) {
                list.remove(list.getSize() / 2);
            }

            timer.stop();
            totalRemoveMiddle += timer.getElapsedTime();

            int valueToFind = rand();

            timer.start();

            for (int i = 0; i < 1000; i++) {
                list.find(valueToFind);
            }

            timer.stop();
            totalFind += timer.getElapsedTime();
        }

        std::cout << "Rozmiar: " << n << std::endl;

        std::cout << "push_back avg: "
                  << totalPushBack / repetitions
                  << " ns" << std::endl;

        std::cout << "insert middle avg: "
                  << totalInsertMiddle / repetitions
                  << " ns" << std::endl;

        std::cout << "remove middle avg: "
                  << totalRemoveMiddle / repetitions
                  << " ns" << std::endl;

        std::cout << "find avg: "
                  << totalFind / repetitions
                  << " ns" << std::endl;

        std::cout << "------------------------" << std::endl;
    }

    return 0;
}