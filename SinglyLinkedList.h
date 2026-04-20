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

    // Pointer to the first node in the list.
    Node* head;
    // Tail keeps push_back in constant time.
    Node* tail;
    // Current number of stored elements.
    int size;

public:
    // Create an empty list.
    SinglyLinkedList();
    // Free all allocated nodes.
    ~SinglyLinkedList();
    // Create a deep copy of another list.
    SinglyLinkedList(const SinglyLinkedList& other);
    // Replace current contents with a deep copy.
    SinglyLinkedList& operator=(const SinglyLinkedList& other);

    // Insert a new value at the given position.
    void insert(int index, int data);
    // Add a new value at the beginning of the list.
    void push_front(int data);
    // Add a new value at the end of the list.
    void push_back(int data);

    // Remove the value at the given position.
    void remove(int index);
    // Remove the first element.
    void pop_front();
    // Remove the last element.
    void pop_back();

    // Display all elements in order.
    void print() const;
    // Delete all elements from the list.
    void clear();
    // Return the current number of elements.
    int getSize() const;
    // Return the index of the searched value.
    [[nodiscard]] int find(int data) const;

};


#endif //PROJEKT_1_SINGLYLINKEDLIST_H
