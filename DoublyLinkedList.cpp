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

    Node* temp;

    if (index <= size / 2) {
        temp = head;

        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
    } else {
        temp = tail;

        for (int i = size - 1; i > index - 1; i--) {
            temp = temp->prev;
        }
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

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

void DoublyLinkedList::push_back(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    temp->prev = tail;

    if (tail != nullptr) {
        tail->next = temp;
    } else {
        head = temp;
    }

    tail = temp;
    size++;
}

void DoublyLinkedList::remove(int index) {
    if (index < 0 || index >= size) {
        return;
    }

    if (index == 0) {
        pop_front();
        return;
    }

    if (index == size - 1) {
        pop_back();
        return;
    }

    Node* temp;

    if (index <= size / 2) {
        temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
    } else {
        temp = tail;

        for (int i = size - 1; i > index; i--) {
            temp = temp->prev;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    size--;
}

void DoublyLinkedList::pop_front() {
    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;
    size--;
}


void DoublyLinkedList::pop_back() {
    Node* temp = tail;
    tail = tail->prev;
    if (tail == nullptr) {
        head = nullptr;
    }
    else {
        tail->next = nullptr;
    }


    delete temp;
    size--;

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

int DoublyLinkedList::getSize() const{
    return size;
}


int DoublyLinkedList::find(int data) const {
    Node* temp = head;
    int index = 0;
    while (temp != nullptr) {
        if (temp->data == data) {
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1;
}


