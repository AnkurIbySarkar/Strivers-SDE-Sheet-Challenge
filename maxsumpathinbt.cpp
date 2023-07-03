#include <iostream>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

long long maxsumhelper(TreeNode<int> *root, long long &maxi)
{
    if (root == NULL)
        return 0;

    long long leftsum = max(0LL, maxsumhelper(root->left, maxi));
    long long rightsum = max(0LL, maxsumhelper(root->right, maxi));

    maxi = max(maxi, (leftsum + rightsum + root->val));

    return max(leftsum, rightsum) + root->val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    if (root == NULL || root->left == NULL || root->right == NULL)
        return -1;
    long long maxi = INT_MIN; // Initialize maxi with the minimum possible value
    maxsumhelper(root, maxi);
    return maxi;
}