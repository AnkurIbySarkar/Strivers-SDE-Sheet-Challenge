#include <iostream>
#include <set>
using namespace std;
int distinctSubstring(string &word)
{
    //  Write your code here.
    set<string> st;
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
        string str = "";
        for (int j = i; j < n; j++)
        {
            str += word[j];
            st.insert(str);
        }
    }
    return st.size();
}
class Node
{
public:
    Node *links[26];
    bool containsKey(char ch)
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
};
int distinctSubstring(string &word)
{
    Node *root = new Node();
    int cnt = 0;
    for (int i = 0; i < word.size(); i++)
    {
        Node *node = root;
        for (int j = i; j < word.size(); j++)
        {
            if (!node->containsKey(word[j]))
            {
                node->put(word[j], new Node());
                cnt++;
            }
            node = node->get(word[j]);
        }
    }
    return cnt;
}