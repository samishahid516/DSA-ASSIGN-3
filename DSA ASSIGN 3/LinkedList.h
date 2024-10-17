#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct Node
{
    int info;
    Node* next;
    Node* pre;
};

class LinkedList
{
private:
    Node* List;

public:
    LinkedList();
    ~LinkedList();

    void traverse();
    Node* find(int);
    void insertAtStart(int);
    int deleteAtStart();
    void insertAtEnd(int);
    int deleteAtEnd();
    void insertAfterValue(int, int);
    int deleteAfterValue(int);
};

#endif
