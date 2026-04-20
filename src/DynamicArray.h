#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <iostream>

// Minimal resizable array used by the UI and benchmark code.
template<typename T>
class DynamicArray {
private:
    T* data;
    int size;
    int capacity;

    void resize();

public:
    DynamicArray();
    ~DynamicArray();

    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);

    T& operator[](int index);
    const T& operator[](int index) const;

    void insert(int index, T value);
    void push_front(T value);
    void push_back(T value);

    void remove(int index);
    void pop_front();
    void pop_back();

    int find(T value) const;
    int getSize() const;
    bool isEmpty() const;

    void clear();
    void print() const;
};

template<typename T>
DynamicArray<T>::DynamicArray()
    : capacity(1), size(0) {
    // Allocate the initial storage buffer.
    data = new T[capacity];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) {
    size = other.size;
    capacity = other.capacity;

    data = new T[capacity];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {
    if (this == &other) {
        return *this;
    }

    delete[] data;

    size = other.size;
    capacity = other.capacity;

    data = new T[capacity];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }

    return *this;
}

template<typename T>
T& DynamicArray<T>::operator[](int index) {
    return data[index];
}

template<typename T>
const T& DynamicArray<T>::operator[](int index) const {
    return data[index];
}


template<typename T>
void DynamicArray<T>::resize() {
    // Double capacity to keep growth amortized efficient.
    int newCapacity = 2 * capacity;
    T* newData = new T[newCapacity];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template<typename T>
void DynamicArray<T>::insert(int index, T value) {
    if (index < 0 || index > size) {
        std::cout << "Insert error: index " << index << " out of range" << std::endl;
        return;
    }

    // Grow the array if there is no free space left.
    if (size == capacity) {
        resize();
    }

    // Shift the suffix right to open the requested slot.
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }

    // Store the new value in the requested position.
    data[index] = value;
    size++;
}

// Insert a value at the front of the array.
template<typename T>
void DynamicArray<T>::push_front(T value) {
    // Insert at index 0 to place the value at the beginning.
    insert(0, value);
}

// Append a value to the end of the array.
template<typename T>
void DynamicArray<T>::push_back(T value) {
    // Insert at the current size to append the value.
    insert(size, value);
}

// Remove the value at the given index.
template<typename T>
void DynamicArray<T>::remove(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Remove error: index " << index << " out of range" << std::endl;
        return;
    }

    // Shift remaining elements left to close the removed gap.
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }

    // Reduce the logical size after removing the element.
    size--;
}

template<typename T>
void DynamicArray<T>::pop_front() {
    // Reuse remove() for the first element.
    remove(0);
}

template<typename T>
void DynamicArray<T>::pop_back() {
    // Reuse remove() for the last element.
    remove(size - 1);
}

template<typename T>
int DynamicArray<T>::find(T value) const {
    // Check each element until the searched value is found.
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return i;
        }
    }

    return -1;
}

template<typename T>
int DynamicArray<T>::getSize() const {
    return size;
}

// Return true if the array is empty.
template<typename T>
bool DynamicArray<T>::isEmpty() const {
    // The array is empty when it stores no elements.
    return size == 0;
}

// Remove all elements from the array.
template<typename T>
void DynamicArray<T>::clear() {
    // Reset the logical size without reallocating memory.
    size = 0;
}

template<typename T>
void DynamicArray<T>::print() const {
    // Print basic information and all stored values.
    std::cout << "size=" << size << " capacity=" << capacity << " : ";

    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;
}

#endif
