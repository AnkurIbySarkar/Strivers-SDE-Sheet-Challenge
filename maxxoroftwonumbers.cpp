#include <iostream>
#include <vector>
using namespace std;
int maximumXor(vector<int> A)
{
    // Write your code here.
    int max_ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            int curr_xor = A[i] ^ A[j];
            max_ans = max(curr_xor, max_ans);
        }
    }
    return max_ans;
}
class Node
{
public:
    Node *links[2];
    bool containsKey(int ind)
    {
        return (links[ind] != NULL);
    }
    Node *get(int ind)
    {
        return links[ind];
    }
    void put(int ind, Node *node)
    {
        links[ind] = node;
    }
};
class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int findMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
int maximumXor(vector<int> A)
{
    // Write your code here.
    Trie trie;
    for (int i = 0; i < A.size(); i++)
    {
        trie.insert(A[i]);
    }
    int maxi = 0;
    for (int i = 0; i < A.size(); i++)
    {
        maxi = max(maxi, trie.findMax(A[i]));
    }
    return maxi;
}