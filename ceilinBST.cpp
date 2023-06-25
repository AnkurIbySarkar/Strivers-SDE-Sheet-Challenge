#include <iostream>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
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
int findCeil(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
    int ceil = -1;
    while (root != NULL)
    {
        if (root->data == x)
        {
            ceil = root->data;
            return ceil;
        }
        if (root->data > x)
        {
            ceil = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ceil;
}