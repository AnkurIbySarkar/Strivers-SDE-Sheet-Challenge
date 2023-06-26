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
            delete left;
        if (right)
            delete right;
    }
};

bool issymmetricHelp(BinaryTreeNode<int> *left, BinaryTreeNode<int> *right)
{
    if (left == NULL || right == NULL)
        return left == right;
    if (left->data != right->data)
        return false;
    return issymmetricHelp(left->left, right->right) && issymmetricHelp(left->right, right->left);
}
bool isSymmetric(BinaryTreeNode<int> *root)
{
    // Write your code here.
    return root == NULL || issymmetricHelp(root->left, root->right);
}