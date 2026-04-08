//
// Created by Karol Nalepa on 09/04/2026.
//


#ifndef PROJEKT_1_BENCHMARKSAVER_H
#define PROJEKT_1_BENCHMARKSAVER_H
#include <string>


class BenchmarkSaver {
public:
    static void saveOperationResults(
        const std::string& filename,
        int sizes[],
        double dynamicArray[],
        double singlyLinkedList[],
        double doublyLinkedList[],
        int count
    );
};

#endif //PROJEKT_1_BENCHMARKSAVER_H
