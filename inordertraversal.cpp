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
void inorderTraversal(TreeNode *root, vector<int> &ds)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, ds);
    ds.push_back(root->data);
    inorderTraversal(root->right, ds);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    inorderTraversal(root, ans);
    return ans;
}