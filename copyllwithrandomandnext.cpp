#include <iostream>
#include <unordered_map>
using namespace std;
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    unordered_map<LinkedListNode<int> *, LinkedListNode<int> *> hashmap;
    LinkedListNode<int> *temp = head;
    while (temp != NULL)
    {
        LinkedListNode<int> *newnode = new LinkedListNode<int>(temp->data);
        hashmap[temp] = newnode;
        temp = temp->next;
    }
    LinkedListNode<int> *t = head;
    while (t)
    {
        LinkedListNode<int> *node = hashmap[t];
        node->next = (t->next != NULL) ? hashmap[t->next] : NULL;
        node->random = (t->random != NULL) ? hashmap[t->random] : NULL;
        t = t->next;
    }
    return hashmap[head];
}
