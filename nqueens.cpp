#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int row, int col, vector<int> &board, int n)
{
    int dupcol = col;
    int duprow = row;

    while (col >= 0 && row >= 0)
    {
        if (board[row * n + col] == 1)
            return false;
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;
    while (col >= 0)
    {
        if (board[row * n + col] == 1)
            return false;
        col--;
    }

    col = dupcol;
    row = duprow;
    while (col >= 0 && row < n)
    {
        if (board[row * n + col] == 1)
            return false;
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<int> &board, vector<vector<int>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row * n + col] = 1;
            solve(col + 1, board, ans, n);
            board[row * n + col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> ans;
    vector<int> board(n * n, 0);
    solve(0, board, ans, n);
    return ans;
}
void solve(vector<vector<int>> &ans, int col, int n,
           vector<vector<int>> &board,
           vector<int> &leftrow,
           vector<int> &lowerdig,
           vector<int> &upperdig)
{

    if (col == n)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftrow[row] == 0 && lowerdig[row + col] == 0 && upperdig[n - 1 + col - row] == 0)
        {
            board[row][col] = 1;
            leftrow[row] = 1;
            lowerdig[row + col] = 1;
            upperdig[n - 1 + col - row] = 1;
            solve(ans, col + 1, n, board, leftrow, lowerdig, upperdig);
            board[row][col] = 0;
            leftrow[row] = 0;
            lowerdig[row + col] = 0;
            upperdig[n - 1 + col - row] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> leftrow(n, 0);
    vector<int> lowerdig(2 * n - 1, 0);
    vector<int> upperdig(2 * n - 1, 0);

    solve(ans, 0, n, board, leftrow, lowerdig, upperdig);

    return ans;
}