#include "LinkedList.h"

int main()
{
    LinkedList dll;

    dll.insertAtStart(10);
    dll.insertAtStart(20);
    dll.insertAtEnd(30);
    dll.traverse();                    // Output: 20 10 30

    dll.deleteAtStart();
    dll.traverse();                    // Output: 10 30

    dll.deleteAtEnd();
    dll.traverse();                    // Output: 10

    dll.insertAfterValue(10, 15);
    dll.traverse();                    // Output: 10 15

    dll.deleteAfterValue(10);
    dll.traverse();                    // Output: 10

    return 0;
}
