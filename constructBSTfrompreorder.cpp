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
    ~TreeNode()
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

TreeNode<int> *Build(vector<int> &preOrder, int &i, int upperbound)
{
    if (i == preOrder.size() || preOrder[i] > upperbound)
        return NULL;
    TreeNode<int> *root = new TreeNode<int>(preOrder[i++]);
    root->left = Build(preOrder, i, root->data);
    root->right = Build(preOrder, i, upperbound);
}
TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    int i = 0;
    return Build(preOrder, i, INT_MAX);
}