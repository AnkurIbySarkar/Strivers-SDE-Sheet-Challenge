#include <iostream>
#include <vector>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
void preorder(TreeNode *root, vector<int> &ds)
{
    if (root == NULL)
        return;
    ds.push_back(root->data);
    preorder(root->left, ds);
    preorder(root->right, ds);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    preorder(root, ans);
    return ans;
}