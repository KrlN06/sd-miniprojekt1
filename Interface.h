//
// Created by Michał Marszałek on 06/04/2026.
//
#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include "DynamicArray.h" 
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "Benchmark.h"

class Interface {
public:
    Interface();
    void run();

private:
    // The menu works on one live instance of each structure.
    DynamicArray<int> dynArray; 
    SinglyLinkedList sList;
    DoublyLinkedList dList;
    // Used to print the banner only once.
    bool firstRun;

    void displayMainMenu();
    void handleMainMenuChoice(int choice);
    
    void displayStructureMenu(const std::string& structureName);
    void handleStructureMenuChoice(int choice, int structureType);
    
    void displayAddMenu();
    void handleAddMenuChoice(int choice, int structureType);
    
    void displayRemoveMenu();
    void handleRemoveMenuChoice(int choice, int structureType);
    
    void handleFindOperation(int structureType);
    void handleDisplayOperation(int structureType);
    void handleGenerateRandomOperation(int structureType);
    void handleLoadFromFileOperation(int structureType);
    void handleClearOperation(int structureType);
    
    void displayBenchmarkMenu();
    void handleBenchmarkMenuChoice(int choice);
    void runFullBenchmark();

    
    void clearScreen();
    void waitForUser();
};

#endif // INTERFACE_H
