//
// Created by KN on 14.03.2026.
//
#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray() {
    capacity = 1;
    size = 0;
    data = new int[capacity];
}

DynamicArray::~DynamicArray() {
    delete [] data;
}

void insert(int index, int value) {
    std::cout<<"DynamicArray::insert()"<<std::endl;
}

void push_front(int value) {
    std::cout<<"DynamicArray::push_front()"<<std::endl;
}
void push_back(int value) {
    std::cout<<"DynamicArray::push_back()"<<std::endl;
}
void remove(int index) {
    std::cout<<"DynamicArray::remove()"<<std::endl;
}
void remove_front() {
    std::cout<<"DynamicArray::remove_front()"<<std::endl;
}
void remove_back() {
    std::cout<<"DynamicArray::remove_back()"<<std::endl;
}

int find(int value) {
    std::cout<<"DynamicArray::find()"<<std::endl;
    return 1;
}

int getSize() {
    std::cout<<"DynamicArray::getSize()"<<std::endl;
    return size;
}
bool isEmpty() {
    std::cout<<"DynamicArray::isEmpty()"<<std::endl;
    return size == 0;
}

void DynamicArray::print() {
    std::cout<<"DynamicArray print()"<<std::endl;
}
