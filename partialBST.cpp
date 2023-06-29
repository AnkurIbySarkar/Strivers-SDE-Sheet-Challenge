#include <iostream>
#include <vector>
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
};
bool validate(BinaryTreeNode<int> *root, long long lb, long long ub)
{
    if (root == NULL)
        return true;
    if (root->data > ub || root->data < lb)
        return false;
    return validate(root->left, lb, root->data) && validate(root->right, root->data, ub);
}
bool validateBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    return validate(root, LONG_MIN, LONG_MAX);
}