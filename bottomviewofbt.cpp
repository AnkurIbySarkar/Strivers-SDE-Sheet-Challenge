#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    // Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mpp;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        BinaryTreeNode<int> *temp = it.first;
        int line = it.second;
        mpp[line] = temp->data;
        if (temp->left != NULL)
        {
            q.push({temp->left, line - 1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, line + 1});
        }
    }
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
