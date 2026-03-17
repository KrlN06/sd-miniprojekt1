//
// Created by KN on 17.03.2026.
//

#ifndef PROJEKT_1_SINGLYLINKEDLIST_H
#define PROJEKT_1_SINGLYLINKEDLIST_H

struct Node {
    int data;
    Node* next;
};


class SinglyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void insert(int index, int data);
    void push_front(int data);
    void push_back(int data);

    void remove(int index);
    void pop_front();
    void pop_back();

    void print();
    void clear();
    int getSize();
    int find(int data);

};


#endif //PROJEKT_1_SINGLYLINKEDLIST_H
