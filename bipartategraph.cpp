#include <iostream>
#include <vector>
using namespace std;
bool dfs(int node, vector<int> adj[], vector<int> &vis)
{

    for (auto it : adj[node])
    {
        if (vis[it] == -1)
        {
            vis[it] = 1 - vis[node];
            if (dfs(it, adj, vis) == false)
                return false;
        }
        else if (vis[it] == vis[node])
        {
            return false;
        }
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // Write your code here.
    int n = edges.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j])
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            if (!dfs(i, adj, color))
                return false;
        }
    }
    return true;
}