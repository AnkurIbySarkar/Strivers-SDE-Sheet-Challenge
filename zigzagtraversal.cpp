#include <iostream>
#include <vector>
#include <queue>
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
        left = NULL;
        right = NULL;
    }
};

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> res;
    if (root == NULL)
        return res;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool lefttoright = true;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> sub(n);
        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int> *curr = q.front();
            q.pop();
            int index = lefttoright ? i : n - i - 1;
            sub[index] = curr->data;

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        lefttoright = !lefttoright;
        for (auto i : sub)
        {
            res.push_back(i);
        }
    }
    return res;
}
