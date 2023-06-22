#include <iostream>
using namespace std;
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    // Write your code here
    LinkedListNode<int> *Newhead = NULL;
    while (head != NULL)
    {
        LinkedListNode<int> *next = head->next;
        head->next = Newhead;
        Newhead = head;
        head = next;
    }
    return Newhead;
}