#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void toposort(vector<int> adj[], int node, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            toposort(adj, it, vis, st);
        }
    }
    st.push(node);
}
void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &ans)
{
    vis[node] = 1;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, ans);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> vis(n, 0);
    vector<int> adj[n], adjT[n];
    stack<int> st;
    vector<vector<int>> res;
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            toposort(adj, i, vis, st);
    }
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        vector<int> ans;
        if (!vis[node])
        {
            dfs(node, vis, adjT, ans);
            res.push_back(ans);
        }
    }
    return res;
}