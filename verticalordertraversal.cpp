#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
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
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> result;

    if (root == nullptr)
        return result;

    map<int, vector<int>> nodeMap;
    queue<pair<TreeNode<int> *, int>> nodeQueue;

    // Enqueue the root node with vertical distance 0
    nodeQueue.push({root, 0});

    while (!nodeQueue.empty())
    {
        auto current = nodeQueue.front();
        nodeQueue.pop();

        auto node = current.first;
        int verticalDistance = current.second;

        // Add the node's value to the corresponding vertical distance group
        nodeMap[verticalDistance].push_back(node->data);

        // Enqueue the left child with the updated vertical distance
        if (node->left != nullptr)
            nodeQueue.push({node->left, verticalDistance - 1});

        // Enqueue the right child with the updated vertical distance
        if (node->right != nullptr)
            nodeQueue.push({node->right, verticalDistance + 1});
    }

    // Concatenate all the vertical order groups into a single result vector
    for (const auto &entry : nodeMap)
    {
        const vector<int> &group = entry.second;
        result.insert(result.end(), group.begin(), group.end());
    }

    return result;
}