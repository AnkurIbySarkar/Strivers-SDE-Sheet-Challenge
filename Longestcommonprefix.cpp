#include <iostream>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    if (arr.empty())
        return "";
    int ans = arr[0].length();
    for (int i = 1; i < n; i++)
    {
        int j = 0;
        while (j < n && arr[i][j] == arr[0][j])
            j++;
        ans = min(ans, j);
    }
    return arr[0].substr(0, ans);
}
