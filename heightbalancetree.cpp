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
};
int getHeight(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = getHeight(root->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = getHeight(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    return max(leftHeight, rightHeight) + 1;
}
bool isBalancedBT(BinaryTreeNode<int> *root)
{
    // Write your code here.
    return getHeight(root) != -1;
}