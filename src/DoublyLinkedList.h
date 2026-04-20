//
// Created by Karol Nalepa on 02/04/2026.
//


#ifndef PROJEKT_1_DOUBLYLINKEDLIST_H
#define PROJEKT_1_DOUBLYLINKEDLIST_H



class DoublyLinkedList {

private:
    struct Node {
        // Each node links to both neighbors for bidirectional traversal.
        int data;
        Node* next;
        Node* prev;
    };
    // Keeping both ends makes front and back updates cheap.
    int size;
    Node* head;
    Node* tail;

public:

    // Create an empty list.
    DoublyLinkedList();
    // Free all allocated nodes.
    ~ DoublyLinkedList();
    // Create a deep copy of another list.
    DoublyLinkedList(const DoublyLinkedList& other);
    // Replace current contents with a deep copy.
    DoublyLinkedList& operator=(const DoublyLinkedList& other);

    // Insert a new value at the given position.
    void insert (int index, int data);
    // Add a new value at the beginning of the list.
    void push_front (int data);
    // Add a new value at the end of the list.
    void push_back (int data);

    // Remove the value at the given position.
    void remove (int index);
    // Remove the first element.
    void pop_front();
    // Remove the last element.
    void pop_back();

    // Display all elements in order.
    void print();
    // Delete all elements from the list.
    void clear();
    // Return the current number of elements.
    int getSize () const;
    // Return the index of the searched value.
    [[nodiscard]] int find(int data) const;

};


#endif //PROJEKT_1_DOUBLYLINKEDLIST_H
