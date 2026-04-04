#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <iostream>

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

    if (size == capacity) {
        resize();
    }

    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }

    data[index] = value;
    size++;
}

template<typename T>
void DynamicArray<T>::push_front(T value) {
    insert(0, value);
}

template<typename T>
void DynamicArray<T>::push_back(T value) {
    insert(size, value);
}

template<typename T>
void DynamicArray<T>::remove(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Remove error: index " << index << " out of range" << std::endl;
        return;
    }

    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }

    size--;
}

template<typename T>
void DynamicArray<T>::pop_front() {
    remove(0);
}

template<typename T>
void DynamicArray<T>::pop_back() {
    remove(size - 1);
}

template<typename T>
int DynamicArray<T>::find(T value) const {
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

template<typename T>
bool DynamicArray<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
void DynamicArray<T>::clear() {
    size = 0;
}

template<typename T>
void DynamicArray<T>::print() const {
    std::cout << "size=" << size << " capacity=" << capacity << " : ";

    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;
}

#endif