//
// Created by Karol Nalepa on 09/04/2026.
//


#ifndef PROJEKT_1_BENCHMARKSAVER_H
#define PROJEKT_1_BENCHMARKSAVER_H
#include <string>
#include "DynamicArray.h"


class BenchmarkSaver {
public:
    static void saveOperationResults(
        const std::string& filename,
        int sizes[],
        const DynamicArray<long long>& dynamicArray,
        const DynamicArray<long long>& singlyLinkedList,
        const DynamicArray<long long>& doublyLinkedList,
        int count
    );
};

#endif //PROJEKT_1_BENCHMARKSAVER_H
