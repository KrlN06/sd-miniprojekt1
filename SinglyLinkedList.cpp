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



void SinglyLinkedList::insert(int index, int data) {
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

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;

    size++;
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
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void SinglyLinkedList::remove(int index) {

    if (index < 0 || index >= size || head == nullptr) {
        return;
    }

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }

        size--;
        return;
    }

    Node* temp = head;

    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    Node* to_delete = temp->next;
    temp->next = to_delete->next;

    if (to_delete == tail) {
        tail = temp;
    }

    delete to_delete;
    size--;
}

void SinglyLinkedList::pop_front() {
    remove(0);
}

void SinglyLinkedList::pop_back() {
    remove(size-1);
}

void SinglyLinkedList::print() const{
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

int SinglyLinkedList::getSize() const{
    return size;
}

int SinglyLinkedList::find(int data) const{
    Node* temp = head;
    int index = 0;
    while (temp != nullptr) {
        if (temp->data == data) {
            return index;
        }
        index++;
        temp = temp -> next;
    }
    return -1;
}

