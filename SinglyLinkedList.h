//
// Created by KN on 17.03.2026.
//

#ifndef PROJEKT_1_SINGLYLINKEDLIST_H
#define PROJEKT_1_SINGLYLINKEDLIST_H



class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

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

    void print() const;
    void clear();
    int getSize() const;
    [[nodiscard]] int find(int data) const;

};


#endif //PROJEKT_1_SINGLYLINKEDLIST_H
