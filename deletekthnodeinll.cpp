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

Node *removeKthNode(Node *head, int K)
{
    // Write your code here.
    int length = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        length++;
        curr = curr->next;
    }
    int position = length - K;
    if (position <= 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    curr = head;
    for (int i = 0; i < position - 1; i++)
    {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}
Node *removeKthNode(Node *head, int K)
{
    // Write your code here.
    Node *start = new Node();
    start->next = head;
    Node *fast = start;
    Node *slow = start;
    for (int i = 1; i <= K; i++)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return start->next;
}
