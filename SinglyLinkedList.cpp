//
// Created by KN on 17.03.2026.
//

#include "SinglyLinkedList.h"
#include <iostream>

SinglyLinkedList::SinglyLinkedList() {
    size = 0;
    tail = nullptr;
    head = nullptr;
}

SinglyLinkedList::~SinglyLinkedList() {
    clear();
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

void SinglyLinkedList::push_back(int data) {
    tail->next = new Node;
    tail = tail -> next;
    if (tail == nullptr) {
        tail = new Node;
    }
    size++;
}


void SinglyLinkedList::print() {
    Node* temp = head;

    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}

void SinglyLinkedList::clear() {
    Node* temp = head;

    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}
