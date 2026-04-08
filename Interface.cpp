#include "Interface.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

Interface::Interface() : firstRun(true) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Interface::clearScreen() {
#ifdef _WIN32
    system("cls");
#elif __APPLE__ || __linux__
    for (int i = 0; i < 50; i++) {
        std::cout << '\n';
    }
#endif
}

void Interface::waitForUser() {
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore(10000, '\n');
    std::cin.get();
}

void Interface::run() {
    int choice = 0;
    while (true) {
        clearScreen();
        displayMainMenu();
        std::cin >> choice;
        handleMainMenuChoice(choice);
    }
}

void Interface::displayMainMenu() {
    if (firstRun) {
        std::cout << "PROJECT 1 DATA STRUCTURES\n"
                  << "KAROL NALEPA MICHAŁ MARSZAŁEK\n\n";
        firstRun = false;
    }
    std::cout << "Select mode:\n"
              << "Dynamic array [1]\n"
              << "Singly linked list [2]\n"
              << "Doubly linked list [3]\n"
              << "Benchmark [4]\n"
              << "Quit [5]\n"
              << "Your choice: ";
}

void Interface::handleMainMenuChoice(int choice) {
    switch (choice) {
        case 1:
            displayStructureMenu("DYNAMIC ARRAY");
            break;
        case 2:
            displayStructureMenu("SINGLY LINKED LIST");
            break;
        case 3:
            displayStructureMenu("DOUBLY LINKED LIST");
            break;
        case 4:
            displayBenchmarkMenu();
            break;
        case 5:
            clearScreen();
            std::cout << "Exiting program. Goodbye!\n";
            exit(0);
        default:
            std::cout << "Invalid choice. Please try again.\n";
            waitForUser();
    }
}

void Interface::displayStructureMenu(const std::string& structureName) {
    int choice = 0;
    int structureType = 0;
    
    if (structureName == "DYNAMIC ARRAY") structureType = 1;
    else if (structureName == "SINGLY LINKED LIST") structureType = 2;
    else if (structureName == "DOUBLY LINKED LIST") structureType = 3;

    while (true) {
        clearScreen();
        std::cout << "--- " << structureName << " MENU ---\n"
                  << "Select operation category:\n"
                  << "Add operations            [1]\n"
                  << "Remove operations         [2]\n"
                  << "Find operation            [3]\n"
                  << "Display structure         [4]\n"
                  << "Generate random structure [5]\n"
                  << "Load structure from file  [6]\n"
                  << "Clear structure           [7]\n"
                  << "Return to main menu       [8]\n"
                  << "Your choice: ";
        std::cin >> choice;
        
        if (choice == 8) break;
        handleStructureMenuChoice(choice, structureType);
    }
}

void Interface::handleStructureMenuChoice(int choice, int structureType) {
    switch (choice) {
        case 1:
            clearScreen();
            displayAddMenu();
            std::cin >> choice;
            handleAddMenuChoice(choice, structureType);
            waitForUser();
            break;
        case 2:
            clearScreen();
            displayRemoveMenu();
            std::cin >> choice;
            handleRemoveMenuChoice(choice, structureType);
            waitForUser();
            break;
        case 3:
            handleFindOperation(structureType);
            waitForUser();
            break;
        case 4:
            handleDisplayOperation(structureType);
            waitForUser();
            break;
        case 5:
            handleGenerateRandomOperation(structureType);
            waitForUser();
            break;
        case 6:
            handleLoadFromFileOperation(structureType);
            waitForUser();
            break;
        case 7:
            handleClearOperation(structureType);
            std::cout << "Structure has been cleared.\n";
            waitForUser();
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            waitForUser();
    }
}

void Interface::displayAddMenu() {
    std::cout << "--- ADD OPERATIONS ---\n"
              << "Select add operation:\n"
              << "Add at beginning       [1]\n"
              << "Add at end             [2]\n"
              << "Add at random position [3]\n"
              << "Return                 [4]\n"
              << "Your choice: ";
}

void Interface::handleAddMenuChoice(int choice, int structureType) {
    if (choice == 4) return;

    int value;
    std::cout << "Enter value to add: ";
    std::cin >> value;

    switch (choice) {
        case 1:
            if (structureType == 1) dynArray.push_front(value);
            else if (structureType == 2) sList.push_front(value);
            else if (structureType == 3) dList.push_front(value);
            std::cout << "Element successfully added at the beginning.\n";
            break;
        case 2:
            if (structureType == 1) dynArray.push_back(value);
            else if (structureType == 2) sList.push_back(value);
            else if (structureType == 3) dList.push_back(value);
            std::cout << "Element successfully added at the end.\n";
            break;
        case 3: {
            int currentSize = 0;
            if (structureType == 1) currentSize = dynArray.getSize();
            else if (structureType == 2) currentSize = sList.getSize();
            else if (structureType == 3) currentSize = dList.getSize();

            int index = (currentSize == 0) ? 0 : (rand() % (currentSize + 1));

            if (structureType == 1) dynArray.insert(index, value);
            else if (structureType == 2) sList.insert(index, value);
            else if (structureType == 3) dList.insert(index, value);
            std::cout << "Element successfully added at random position (index: " << index << ").\n";
            break;
        }
        default:
            std::cout << "Invalid choice.\n";
    }
}

void Interface::displayRemoveMenu() {
    std::cout << "--- REMOVE OPERATIONS ---\n"
              << "Select remove operation:\n"
              << "Remove from beginning       [1]\n"
              << "Remove from end             [2]\n"
              << "Remove from random position [3]\n"
              << "Return                      [4]\n"
              << "Your choice: ";
}

void Interface::handleRemoveMenuChoice(int choice, int structureType) {
    if (choice == 4) return;

    switch (choice) {
        case 1:
            if (structureType == 1) dynArray.pop_front();
            else if (structureType == 2) sList.pop_front();
            else if (structureType == 3) dList.pop_front();
            std::cout << "Element removed from the beginning.\n";
            break;
        case 2:
            if (structureType == 1) dynArray.pop_back();
            else if (structureType == 2) sList.pop_back();
            else if (structureType == 3) dList.pop_back();
            std::cout << "Element removed from the end.\n";
            break;
        case 3: {
            int currentSize = 0;
            if (structureType == 1) currentSize = dynArray.getSize();
            else if (structureType == 2) currentSize = sList.getSize();
            else if (structureType == 3) currentSize = dList.getSize();

            if (currentSize == 0) {
                std::cout << "Structure is empty. Cannot remove element.\n";
            } else {
                int index = rand() % currentSize;
                if (structureType == 1) dynArray.remove(index);
                else if (structureType == 2) sList.remove(index);
                else if (structureType == 3) dList.remove(index);
                std::cout << "Element removed from random position (index: " << index << ").\n";
            }
            break;
        }
        default:
            std::cout << "Invalid choice.\n";
    }
}

void Interface::handleFindOperation(int structureType) {
    clearScreen();
    int value, index = -1;
    std::cout << "Enter value to find: ";
    std::cin >> value;

    if (structureType == 1) index = dynArray.find(value);
    else if (structureType == 2) index = sList.find(value);
    else if (structureType == 3) index = dList.find(value);

    if (index != -1) {
        std::cout << "Element found at position: " << index << "\n";
    } else {
        std::cout << "Element with the given value not found in the structure.\n";
    }
}

void Interface::handleDisplayOperation(int structureType) {
    clearScreen();
    std::cout << "--- STRUCTURE CONTENT ---\n";
    if (structureType == 1) dynArray.print();
    else if (structureType == 2) sList.print();
    else if (structureType == 3) dList.print();
}

void Interface::handleGenerateRandomOperation(int structureType) {
    clearScreen();
    int count;
    std::cout << "Enter the number of elements to generate: ";
    std::cin >> count;

    handleClearOperation(structureType); 

    for (int i = 0; i < count; i++) {
        int randomVal = rand() % 10000;
        if (structureType == 1) dynArray.push_back(randomVal);
        else if (structureType == 2) sList.push_back(randomVal);
        else if (structureType == 3) dList.push_back(randomVal);
    }
    std::cout << "Generated " << count << " random elements.\n";
}

void Interface::handleLoadFromFileOperation(int structureType) {
    clearScreen();
    std::string filename;
    std::cout << "Enter text file name: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file.\n";
        return;
    }

    handleClearOperation(structureType);

    int val;
    int count = 0;
    while (file >> val) {
        if (structureType == 1) dynArray.push_back(val);
        else if (structureType == 2) sList.push_back(val);
        else if (structureType == 3) dList.push_back(val);
        count++;
    }

    file.close();
    std::cout << "Successfully loaded " << count << " elements from file.\n";
}

void Interface::handleClearOperation(int structureType) {
    if (structureType == 1) dynArray.clear();
    else if (structureType == 2) sList.clear();
    else if (structureType == 3) dList.clear();
}

void Interface::displayBenchmarkMenu() {
    int choice = 0;
    while (true) {
        clearScreen();
        std::cout << "--- BENCHMARK MENU ---\n"
                  << "Select benchmark option:\n"
                  << "Run full benchmark  [1]\n"
                  << "Return to main menu [2]\n"
                  << "Your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            clearScreen();
            runFullBenchmark();
            waitForUser();
        } else if (choice == 2) {
            break;
        } else {
            std::cout << "Invalid choice.\n";
            waitForUser();
        }
    }
}

void Interface::runFullBenchmark() {
    std::cout << "Starting automatic benchmark...\n";

    Benchmark benchmark;
    benchmark.run();

    std::cout << "\nBenchmark finished!\n";
}