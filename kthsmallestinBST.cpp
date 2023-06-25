#include <iostream>
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

int solve(TreeNode<int> *root, int &k)
{
    // Base Case
    if (root == NULL)
        return -1;

    // Left
    int left = solve(root->left, k);
    if (left != -1)
        return left;

    // Current Node
    k--;
    if (k == 0)
        return root->data;

    // Right
    int right = solve(root->right, k);
    return right;
}
int kthSmallest(TreeNode<int> *root, int k)
{
    return solve(root, k);
}