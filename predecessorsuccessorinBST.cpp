#include <iostream>
using namespace std;
template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};
BinaryTreeNode<int> *solve1(BinaryTreeNode<int> *root, int key)
{
    BinaryTreeNode<int> *temp = NULL;
    while (root != NULL)
    {
        if (root->data <= key)
        {
            root = root->right;
        }
        else
        {
            temp = root;
            root = root->left;
        }
    }
    return temp;
}
BinaryTreeNode<int> *solve2(BinaryTreeNode<int> *root, int key)
{
    BinaryTreeNode<int> *temp = NULL;
    while (root != NULL)
    {
        if (root->data >= key)
        {
            root = root->left;
        }
        else
        {
            temp = root;
            root = root->right;
        }
    }
    return temp;
}
pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    // Write your code here.
    int successor = -1;
    int predecessor = -1;
    BinaryTreeNode<int> *curr1 = solve1(root, key);
    BinaryTreeNode<int> *curr2 = solve2(root, key);
    if (curr2 != NULL)
        successor = curr2->data;
    if (curr1 != NULL)
        predecessor = curr1->data;

    return {successor, predecessor};
}
