#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
Node *findMiddle(Node *head)
{
    // Write your code here
    int cnt = 0;
    Node *curr = head;
    Node *middle = head;
    while (curr != NULL)
    {
        curr = curr->next;
        cnt++;
    }
    int mid = cnt / 2;
    while (mid--)
    {
        middle = middle->next;
    }
    return middle;
}
