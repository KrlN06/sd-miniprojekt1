#include "DynamicArray.h"
#include "SinglyLinkedList.h"
#include <iostream>



int main() {
    SinglyLinkedList list;

    list.push_front(5);
    list.push_front(10);
    list.push_front(15);

    list.print();

    //std::cout << "Size: " << list.getSize() << std::endl;

    return 0;
}