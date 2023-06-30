#include <iostream>
#include <vector>
#include <stack>
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

class BSTiterator
{
public:
    stack<TreeNode<int> *> st;
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushAll(root);
    }

    int next()
    {
        // write your code here
        TreeNode<int> *Node = st.top();
        st.pop();
        pushAll(Node->right);
        return Node->data;
    }

    bool hasNext()
    {
        // write your code here
        return !st.empty();
    }
    void pushAll(TreeNode<int> *node)
    {
        for (; node != NULL; st.push(node), node = node->left)
            ;
    }
};