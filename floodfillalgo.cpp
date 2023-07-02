#include <iostream>
#include <vector>
using namespace std;
void solve(int oldcolor, int newColor, int x, int y, int n, int m, vector<vector<int>> &image)
{
    if (x < 0 || x >= n || y < 0 || y >= m || image[x][y] != oldcolor)
    {
        return;
    }
    image[x][y] = newColor;

    solve(oldcolor, newColor, x + 1, y, n, m, image);
    solve(oldcolor, newColor, x - 1, y, n, m, image);
    solve(oldcolor, newColor, x, y + 1, n, m, image);
    solve(oldcolor, newColor, x, y - 1, n, m, image);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int oldcolor = image[x][y];
    if (oldcolor == newColor)
    {
        return image;
    }
    int n = image.size();
    int m = image[0].size();
    solve(oldcolor, newColor, x, y, n, m, image);
    return image;
}