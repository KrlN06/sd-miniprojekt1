cmake_minimum_required(VERSION 4.1)
project(Projekt_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projekt_1 main.cpp
        DynamicArray.h
        SinglyLinkedList.cpp
        SinglyLinkedList.h
        DoublyLinkedList.cpp
        DoublyLinkedList.h
        Timer.cpp
        Timer.h
        Benchmark.cpp
        Benchmark.h
        Interface.cpp
        Interface.h
        Random.cpp
        Random.h
)
