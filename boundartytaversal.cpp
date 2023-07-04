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
bool isLeaf(TreeNode<int> *root)
{
    return !root->left && !root->right;
}
void addLeftBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
        {
            curr = curr->right;
        }
    }
}
void addRightBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
        {
            curr = curr->left;
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}
void addleaves(TreeNode<int> *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addleaves(root->left, res);
    if (root->right)
        addleaves(root->right, res);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> res;
    if (!root)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    addLeftBoundary(root, res);
    addleaves(root, res);
    addRightBoundary(root, res);

    return res;
}