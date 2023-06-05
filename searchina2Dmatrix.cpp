#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size();
    int n = mat[0].size();
    int low = 0, high = n * m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mat[mid / n][mid % n] == target)
        {
            return true;
        }
        else if (mat[mid / n][mid % n] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return false;
}