//
// Created by KN on 14.03.2026.
//
#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray() {
    // Initializes an empty dynamic array with an initial capacity of 1.
    capacity = 1;
    size = 0;
    data = new int[capacity];
}

DynamicArray::~DynamicArray() {
    // Releases the memory allocated for the array.
    delete [] data;
}

void DynamicArray::resize() {
    // Increases the array capacity when there is no space for new elements.
    std::cout<<"DynamicArray::resize()"<<std::endl;
    int newCapacity = 2 * capacity;
    int *newData = new int[newCapacity];
    for (int i = 0; i < capacity; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void DynamicArray::insert(int index, int value) {
    // Inserts an element with the given value at the specified index.
    std::cout<<"DynamicArray::insert()"<<std::endl;
}

void DynamicArray::push_front(int value) {
    // Adds an element to the beginning of the array.
    std::cout<<"DynamicArray::push_front()"<<std::endl;
}

void DynamicArray::push_back(int value) {
    // Adds an element to the end of the array.
    std::cout<<"DynamicArray::push_back()"<<std::endl;

    if(size == capacity) {resize();
    }

    data[size] = value;
    size++;

    }

void DynamicArray::remove(int index) {
    // Removes the element at the specified index.
    std::cout<<"DynamicArray::remove()"<<std::endl;
}

void DynamicArray::remove_front() {
    // Removes the first element from the array.
    std::cout<<"DynamicArray::remove_front()"<<std::endl;
}

void DynamicArray::remove_back() {
    // Removes the last element from the array.
    std::cout<<"DynamicArray::remove_back()"<<std::endl;

    if(size > 0) {
        size --;
    }
}



int DynamicArray::find(int value) {
    // Searches for the given value and returns the index of its occurrence.
    std::cout<<"DynamicArray::find()"<<std::endl;
    return 1;
}

int DynamicArray::getSize() {
    // Returns the current number of elements in the array.
    std::cout<<"DynamicArray::getSize()"<<std::endl;
    return size;
}

bool DynamicArray::isEmpty() {
    // Checks whether the array contains any elements.
    std::cout<<"DynamicArray::isEmpty()"<<std::endl;
    return size == 0;
}

void DynamicArray::clear() {
    // Removes all elements from the array.
    std::cout<<"DynamicArray::clear()"<<std::endl;
}

void DynamicArray::print() {
    // Prints the contents of the array.
    std::cout << "size=" << size << " capacity=" << capacity << " : ";

    for(int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;
}