#include <iostream>
#include <unordered_set>
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
bool detectCycle(Node *head)
{
    //	Write your code here
    unordered_set<Node *> st;
    while (head != NULL)
    {
        if (st.find(head) != st.end())
        {
            return true;
        }
        st.insert(head);
        head = head->next;
    }
    return false;
}

bool detectCycle(Node *head)
{
    //	Write your code here
    if (head == NULL)
        return false;
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}