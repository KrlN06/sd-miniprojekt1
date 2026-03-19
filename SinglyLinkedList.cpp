//
// Created by KN on 17.03.2026.
//

#include "SinglyLinkedList.h"


SinglyLinkedList::SinglyLinkedList() {
    size = 0;
    tail = nullptr;
    head = nullptr;
}

void SinglyLinkedList::push_front(int data) {
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }

    size++;
}
