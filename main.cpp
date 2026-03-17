#include "DynamicArray.h"
#include <iostream>

int main() {
    DynamicArray arr;

    arr.print();
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    arr.print();

    arr.insert(1, 99);
    arr.print();

    arr.remove(2);
    arr.print();

    return 0;
}

