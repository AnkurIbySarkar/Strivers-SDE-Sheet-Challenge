#include <iostream>
#include <vector>
using namespace std;
void dfs(int node, vector<int> adj[], vector<int> &temp, vector<int> &vis)
{
    vis[node] = 1;
    temp.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, temp, vis);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj[V], vis(V);
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<vector<int>> res;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> temp;
            dfs(i, adj, temp, vis);
            res.push_back(temp);
        }
    }
    return res;
}