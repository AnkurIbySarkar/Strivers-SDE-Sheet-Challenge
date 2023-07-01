#include <iostream>
#include <vector>
using namespace std;
bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    // visit adjacent nodes
    for (auto adjacentNode : adj[node])
    {
        // unvisited adjacent node
        if (!vis[adjacentNode])
        {
            if (dfs(adjacentNode, node, vis, adj))
                return true;
        }
        // visited node but not a parent node
        else if (adjacentNode != parent)
            return true;
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    vector<int> Vis(n + 1, 0);
    vector<int> adj[n + 1];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    for (int i = 0; i < n; i++)
    {
        if (!Vis[i])
        {
            if (dfs(i, -1, Vis, adj) == true)
                return "Yes";
        }
    }
    return "No";
}
