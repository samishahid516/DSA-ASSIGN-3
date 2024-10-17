#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    List = NULL;
}

LinkedList::~LinkedList()
{
    while (List != NULL)
        deleteAtStart();
}

void LinkedList::traverse()
{
    for (Node* p = List; p != NULL; p = p->next)
        cout << p->info << " ";
    cout << endl;
}

Node* LinkedList::find(int x)
{
    for (Node* p = List; p != NULL; p = p->next)
    {
        if (p->info == x)
            return p;
    }
    return NULL;
}

void LinkedList::insertAtStart(int x)
{
    Node* p = new Node;
    p->info = x;
    p->pre = NULL;
    p->next = List;
    if (List != NULL)
        List->pre = p;
    List = p;
}

int LinkedList::deleteAtStart()
{
    if (List == NULL)
        return -999;

    Node* p = List;
    List = List->next;
    if (List != NULL)
        List->pre = NULL;

    int x = p->info;
    delete p;
    return x;
}

void LinkedList::insertAtEnd(int x)
{
    if (List == NULL)
    {
        insertAtStart(x);
        return;
    }

    Node* p = List;
    while (p->next != NULL)
        p = p->next;

    Node* q = new Node;
    q->info = x;
    q->next = NULL;
    q->pre = p;
    p->next = q;
}

int LinkedList::deleteAtEnd()
{
    if (List == NULL)
        return -999;

    if (List->next == NULL)
        return deleteAtStart();

    Node* p = List;
    while (p->next != NULL)
        p = p->next;

    int x = p->info;
    p->pre->next = NULL;
    delete p;
    return x;
}

void LinkedList::insertAfterValue(int value, int x)
{
    Node* p = find(value);
    if (p == NULL || p->next == NULL)
    {
        insertAtEnd(x);
        return;
    }

    Node* q = new Node;
    q->info = x;
    q->next = p->next;
    q->pre = p;
    p->next->pre = q;
    p->next = q;
}

int LinkedList::deleteAfterValue(int value)
{
    Node* p = find(value);
    if (p == NULL || p->next == NULL)
        return -999;

    Node* q = p->next;
    p->next = q->next;
    if (q->next != NULL)
        q->next->pre = p;

    int x = q->info;
    delete q;
    return x;
}
