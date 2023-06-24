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
void leftview(TreeNode<int> *root, int level, vector<int> &ds)
{
    if (root == NULL)
        return;
    if (level == ds.size())
    {
        ds.push_back(root->data);
    }
    leftview(root->left, level + 1, ds);
    leftview(root->right, level + 1, ds);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    leftview(root, 0, ans);
    return ans;
}