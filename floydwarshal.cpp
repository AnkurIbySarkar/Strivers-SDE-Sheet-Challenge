#include <iostream>
#include <vector>
using namespace std;
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 1e9));

    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        int wt = i[2];
        adj[u][v] = wt;
    }

    for (int i = 1; i <= n; i++)
    {
        adj[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] != 1e9 && adj[k][j] != 1e9)
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    return adj[src][dest];
}