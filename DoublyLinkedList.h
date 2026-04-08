//
// Created by Karol Nalepa on 02/04/2026.
//


#ifndef PROJEKT_1_DOUBLYLINKEDLIST_H
#define PROJEKT_1_DOUBLYLINKEDLIST_H



class DoublyLinkedList {

private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
    int size;
    Node* head;
    Node* tail;

public:

    DoublyLinkedList();
    ~ DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList& operator=(const DoublyLinkedList& other);


    void insert (int index, int data);
    void push_front (int data);
    void push_back (int data);

    void remove (int index);
    void pop_front();
    void pop_back();

    void print();
    void clear();
    int getSize () const;
    [[nodiscard]] int find(int data) const;

};


#endif //PROJEKT_1_DOUBLYLINKEDLIST_H