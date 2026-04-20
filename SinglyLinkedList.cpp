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
    // Release all dynamically allocated nodes.
    clear();
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other) {
    head = nullptr;
    tail = nullptr;
    size = 0;

    // Copy nodes one by one to preserve the original order.
    Node* temp = other.head;

    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }
}

SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& other) {
    if (this == &other) {
        return *this;
    }

    // Remove current contents before copying new data.
    clear();

    Node* temp = other.head;

    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }

    return *this;
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
    // Stop on the element right before the insertion point.
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    // Create a new node and insert it into the list.
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;

    size++;
}
void SinglyLinkedList::push_front(int data) {
    // Create a new node and move it to the beginning of the list.
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
    // Create a new node and attach it after the current tail.
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
    Node* temp = head;

    // Handle removing the first element separately.
    if (index == 0) {
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
        size--;
        return;
    }

    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    // Bypass the target node before releasing its memory.
    Node* to_delete = temp->next;
    temp->next = to_delete->next;

    if (to_delete == tail) {
        tail = temp;
    }

    delete to_delete;
    size--;
}

void SinglyLinkedList::pop_front() {
    // Reuse remove() for the first element.
    remove(0);
}

void SinglyLinkedList::pop_back() {
    // Reuse remove() for the last element.
    remove(size-1);
}

void SinglyLinkedList::print() const{
    // Traverse the list and display each stored value.
    Node* temp = head;

    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}

void SinglyLinkedList::clear() {
    // Delete every node one by one until the list becomes empty.
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
    // Traverse the list until the requested value is found.
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
