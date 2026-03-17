#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

    void resize();

public:

    DynamicArray();
    ~DynamicArray();

    void insert(int index, int value);
    void push_front(int value);
    void push_back(int value);

    void remove(int index);
    void pop_front();
    void pop_back();

    int find(int value);

    int getSize();
    bool isEmpty();

    void clear();
    void print();

};

#endif
