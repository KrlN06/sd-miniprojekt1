if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.20)
    project(Projekt_1 LANGUAGES CXX)

    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

# Keep the source list local to src so the project also works
# when this directory is opened directly in the IDE.
add_executable(Projekt_1
    main.cpp
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
    BenchmarkSaver.cpp
    BenchmarkSaver.h
)

target_include_directories(Projekt_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
