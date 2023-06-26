#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    Node *links[26];
    bool flag = false;

    bool containskey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containskey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkIfPrefixExists(string word)
    {
        bool f = true;
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containskey(word[i]))
            {
                node = node->get(word[i]);
                f = f & node->isEnd();
            }
            else
            {
                return false;
            }
        }
        return f;
    }
};
string completeString(int n, vector<string> &a)
{
    // Write your code here.
    Trie trie;
    for (auto &it : a)
    {
        trie.insert(it);
    }
    string longest = "";
    for (auto it : a)
    {
        if (trie.checkIfPrefixExists(it))
        {
            if (it.length() > longest.length())
            {
                longest = it;
            }
            else if (it.size() == longest.size() && it < longest)
            {
                longest = it;
            }
        }
    }
    if (longest == "")
        return "None";
    return longest;
}