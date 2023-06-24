#include <iostream>
#include <vector>
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
};

int height(TreeNode<int> *root, int &diameter)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
