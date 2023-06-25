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
    int right = solve(root->right, k);
    if (right != -1)
        return right;

    // Current Node
    k--;
    if (k == 0)
        return root->data;

    // Right
    int left = solve(root->left, k);
    return left;
}
int KthLargestNumber(TreeNode<int> *root, int k)
{
    // Write your code here.
    return solve(root, k);
}