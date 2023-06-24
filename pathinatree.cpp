#include <iostream>
#include <vector>
using namespace std;
template <typename T = int>
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
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

bool getPath(TreeNode<int> *root, vector<int> &ds, int x)
{
    if (root == NULL)
        return false;
    ds.push_back(root->data);
    if (root->data == x)
        return true;

    if (getPath(root->left, ds, x) || getPath(root->right, ds, x))
    {
        return true;
    }
    ds.pop_back();
    return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> ans;
    getPath(root, ans, x);
    return ans;
}
