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
    // Release all dynamically allocated nodes.
    clear();
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &other) {
    head = nullptr;
    tail = nullptr;
    size = 0;

    // Rebuild the list node by node to preserve element order.
    Node* temp = other.head;
    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }
}

DoublyLinkedList & DoublyLinkedList::operator=(const DoublyLinkedList &other) {
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

    // Walk from the closer end to reduce pointer hops.
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

    // Create and connect a new node between two existing nodes.
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    size++;
}

void DoublyLinkedList::push_front(int data) {
    // Create a new node and move it to the beginning of the list.
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
    // Create a new node and attach it after the current tail.
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

    // Walk from the closer end to remove the target node faster.
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

    // Bypass the node being removed by reconnecting neighbors.
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    size--;
}

void DoublyLinkedList::pop_front() {
    // Remove the first node and move head to the next element.
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
    // Remove the last node and move tail to the previous element.
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
    // Traverse the list until the requested value is found.
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

