//
// Created by Karol Nalepa on 02/04/2026.
//

#include "DoublyLinkedList.h"

#include <iostream>

DoublyLinkedList::DoublyLinkedList() {
    size = 0;
    tail = nullptr;
    head = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::insert(int index, int data) {
    if (index < 0 || index > size) {
        return;
    }

    if (index == 0) {
        push_front(data);
        return;
    }

    if (index == size) {
        push_back(data);
        return;
    }


    Node* temp = head;


    for (int i = 0; i < index - 1; i++) {
       temp = temp->next;
    }

    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> next = temp->next;
    newNode -> prev = temp;
    temp -> next = newNode;
    newNode -> next -> prev = newNode;
    size++;

}

void DoublyLinkedList::push_front(int data) {
    Node* temp = head;

    head = new Node();
    head->data = data;
    head->next = temp;
    head->prev = nullptr;

    if (temp != nullptr) {
        temp->prev = head;
    } else {
        tail = head;
    }

    size++;
}


void DoublyLinkedList::clear() {
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

void DoublyLinkedList::print() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int DoublyLinkedList::getSize() {
    return size;
}



