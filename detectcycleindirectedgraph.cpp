#include <iostream>
#include <vector>
using namespace std;
bool dfs(int i, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path)
{
    vis[i] = 1;
    path[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            if (dfs(it, adj, vis, path))
                return true;
        }
        else if (path[it])
            return true;
    }
    path[i] = 0;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    vector<int> vis(n + 1, 0);
    vector<int> dfsvis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, dfsvis))
                return true;
        }
    }
    return false;
}