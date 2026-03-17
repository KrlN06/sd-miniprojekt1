//
// Created by KN on 14.03.2026.
//
#include "DynamicArray.h"
#include <iostream>



DynamicArray::DynamicArray()
// Initializes an empty dynamic array with an initial capacity of 1.
    : capacity(1), size(0)
{
    data = new int[capacity];
}

DynamicArray::~DynamicArray() {
    // Releases the memory allocated for the array.
    delete [] data;
}

void DynamicArray::resize() {
    // Increases the array capacity when there is no space for new elements.
    int newCapacity = 2 * capacity;
    int *newData = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void DynamicArray::insert(int index, int value) {
    // Inserts an element with the given value at the specified index.
    if (index < 0 || index > size) {
        std::cout << "Insert error: index " << index << " out of range" << std::endl;
        return;
    }

    if (size == capacity) {
        resize();
    }

    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }

    data[index] = value;
    size++;
}


void DynamicArray::push_front(int value) {
    // Adds an element to the beginning of the array.
    insert(0, value);
}

void DynamicArray::push_back(int value) {
    // Adds an element to the end of the array.
    insert(size, value);

}

void DynamicArray::remove(int index) {
    // Removes the element at the specified index.
    if (index < 0 || index >= size) {
        std::cout << "Remove error: index " << index << " out of range" << std::endl;
        return;
    }

    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
}



void DynamicArray::remove_front() {
    // Removes the first element from the array.
    remove(0);
}

void DynamicArray::remove_back() {
    // Removes the last element from the array.
    remove(size - 1);
}

int DynamicArray::find(int value) {
    // Searches for the given value and returns the index of its occurrence.
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;

}

int DynamicArray::getSize() {
    // Returns the current number of elements in the array.
    return size;
}

bool DynamicArray::isEmpty() {
    // Checks whether the array contains any elements.
    return size == 0;
}

void DynamicArray::clear() {
    // Removes all elements from the array.
    size = 0;
}

void DynamicArray::print() {
    // Prints the contents of the array.
    std::cout << "size=" << size << " capacity=" << capacity << " : ";

    for(int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;
}
