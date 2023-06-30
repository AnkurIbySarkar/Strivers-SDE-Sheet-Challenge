#include <iostream>
#include <vector>
#include <stack>
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

    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};
class BSTiterator
{
public:
    stack<BinaryTreeNode<int> *> st;
    bool reverse = true; // before
    BSTiterator(BinaryTreeNode<int> *root, bool isReverse)
    {
        // write your code here
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        // write your code here
        BinaryTreeNode<int> *node = st.top();
        st.pop();
        if (!reverse)
        {
            pushAll(node->right);
        }
        else
        {
            pushAll(node->left);
        }
        return node->data;
    }

    bool hasNext()
    {
        // write your code here
        return !st.empty();
    }
    void pushAll(BinaryTreeNode<int> *node)
    {
        for (; node != NULL;)
        {
            st.push(node);
            if (reverse == true)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    if (!root)
        return false;
    BSTiterator l(root, false);
    BSTiterator r(root, true);
    int i = l.next();
    int j = r.next();
    while (i < j)
    {
        if (i + j == k)
            return true;
        else if (i + j < k)
            i = l.next();
        else
            j = r.next();
    }
    return false;
}