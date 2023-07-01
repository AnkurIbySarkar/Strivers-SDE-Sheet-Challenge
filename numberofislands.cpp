#include <iostream>
#include <vector>
using namespace std;

void dfs(int **arr, vector<vector<int>> &visited, int row, int col, int n, int m)
{
    if (row < 0 || row >= n || col < 0 || col >= m || visited[row][col] || arr[row][col] == 0)
        return;

    visited[row][col] = 1;

    dfs(arr, visited, row - 1, col, n, m);
    dfs(arr, visited, row - 1, col + 1, n, m);
    dfs(arr, visited, row, col + 1, n, m);
    dfs(arr, visited, row + 1, col + 1, n, m);
    dfs(arr, visited, row + 1, col, n, m);
    dfs(arr, visited, row + 1, col - 1, n, m);
    dfs(arr, visited, row, col - 1, n, m);
    dfs(arr, visited, row - 1, col - 1, n, m);
}
int getTotalIslands(int **arr, int n, int m)
{
    // Write your code here.
    int count = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && arr[i][j] == 1)
            {
                count++;
                dfs(arr, vis, i, j, n, m);
            }
        }
    }
    return count;
}
