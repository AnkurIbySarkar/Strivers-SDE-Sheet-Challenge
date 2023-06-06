#include <iostream>
#include <unordered_set>

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

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    unordered_set<Node *> st;
    while (firstHead != NULL)
    {
        st.insert(firstHead);
        firstHead = firstHead->next;
    }
    while (secondHead != NULL)
    {
        if (st.find(secondHead) != st.end())
        {
            return secondHead;
        }
        secondHead = secondHead->next;
    }
    return NULL;
}

int getDifference(Node *head1, Node *head2)
{
    int len1 = 0, len2 = 0;
    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            ++len1;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            ++len2;
            head2 = head2->next;
        }
    }
    return len1 - len2; // if difference is neg-> length of list2 > length of list1 else vice-versa
}
Node *findIntersection(Node *head1, Node *head2)
{
    int diff = getDifference(head1, head2);
    if (diff < 0)
        while (diff++ != 0)
            head2 = head2->next;
    else
        while (diff-- != 0)
            head1 = head1->next;
    while (head1 != NULL)
    {
        if (head1 == head2)
            return head1;
        head2 = head2->next;
        head1 = head1->next;
    }
    return head1;
}

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    Node *a = firstHead;
    Node *b = secondHead;
    while (a != b)
    {
        a = a == NULL ? secondHead : a->next;
        b = b == NULL ? firstHead : b->next;
    }
    return a;
}
