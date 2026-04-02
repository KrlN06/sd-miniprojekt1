#include "DynamicArray.h"
#include "SinglyLinkedList.h"
#include <iostream>



int main() {
    SinglyLinkedList list;

    std::cout << "Push back:" << std::endl;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.print();

    std::cout << "Push front:" << std::endl;
    list.push_front(5);
    list.push_front(1);
    list.print();

    std::cout << "Insert at index 2:" << std::endl;
    list.insert(2, 99);
    list.print();

    std::cout << "Remove index 3:" << std::endl;
    list.remove(3);
    list.print();

    std::cout << "Pop front:" << std::endl;
    list.pop_front();
    list.print();

    std::cout << "Pop back:" << std::endl;
    list.pop_back();
    list.print();

    std::cout << "Find 99:" << std::endl;
    std::cout << list.find(99) << std::endl;

    std::cout << "Find 123:" << std::endl;
    std::cout << list.find(123) << std::endl;

    std::cout << "Size:" << std::endl;
    std::cout << list.getSize() << std::endl;

    std::cout << "Clear:" << std::endl;
    list.clear();
    list.print();

    std::cout << "Size after clear:" << std::endl;
    std::cout << list.getSize() << std::endl;

    return 0;
}