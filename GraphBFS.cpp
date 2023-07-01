#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> adj[vertex + 1];
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    for (int i = 0; i < vertex; i++)
    {

        sort(adj[i].begin(), adj[i].end());
    }
    vector<int> vis(vertex, 0);
    vector<int> bfs;

    for (int i = 0; i < vertex; i++)
    {
        queue<int> q;
        if (!vis[i])
        {
            vis[i] = 1;
            q.push(i);
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }
    return bfs;
}