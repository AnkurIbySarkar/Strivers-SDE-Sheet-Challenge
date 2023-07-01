#include <iostream>
#include <vector>
#include <stack>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

class Node
{
public:
    int maxNode, minNode, maxSize;
    Node(int minnode, int maxnode, int maxsize)
    {
        this->maxNode = maxnode;
        this->minNode = minnode;
        this->maxSize = maxsize;
    }
};
Node BSThelper(TreeNode<int> *root)
{
    if (!root)
        return Node(INT_MAX, INT_MIN, 0);
    auto left = BSThelper(root->left);
    auto right = BSThelper(root->right);

    if (left.maxNode < root->data && right.minNode > root->data)
    {
        return Node(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }
    return Node(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
int largestBST(TreeNode<int> *root)
{
    // Write your code here.
    return BSThelper(root).maxSize;
}
