//
// Created by Karol Nalepa on 09/04/2026.
//
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

#include "BenchmarkSaver.h"

void BenchmarkSaver::saveOperationResults(
    const std::string& filename,
    int sizes[],
    const DynamicArray<long long>& dynamicArray,
    const DynamicArray<long long>& singlyLinkedList,
    const DynamicArray<long long>& doublyLinkedList,
    int count
) {
    // Keep benchmark exports in a dedicated folder.
    std::filesystem::create_directory("results");
    std::ofstream file("results/" + filename);

    if (!file.is_open()) {
        std::cout << "Cannot open file: results/" << filename << std::endl;
        return;
    }

    file << "Size,DynamicArray,SinglyLinkedList,DoublyLinkedList\n";

    for (int i = 0; i < count; i++) {
        file << sizes[i] << ","
             << dynamicArray[i] << ","
             << singlyLinkedList[i] << ","
             << doublyLinkedList[i] << "\n";
    }

    file.close();

    std::cout << "Results saved to results/" << filename << std::endl;
}
