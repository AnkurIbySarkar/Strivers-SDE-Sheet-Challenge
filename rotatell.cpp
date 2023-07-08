#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node *rotate(Node *head, int k)
{
    // Write your code here.
    if (head == NULL || head->next == NULL)
        return head;
    for (int i = 0; i < k; i++)
    {
        Node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        Node *end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}
Node *rotate(Node *head, int k)
{
    // Write your code here.
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    int cnt = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    temp->next = head;
    k = k % cnt;
    int end = cnt - k;
    while (end--)
        temp = temp->next;
    head = temp->next;
    temp->next = NULL;

    return head;
}