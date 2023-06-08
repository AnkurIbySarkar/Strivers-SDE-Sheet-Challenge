#include <iostream>
#include <vector>
using namespace std;
vector<long long int> generateRow(int r)
{
    vector<long long int> ans;
    long long int res = 1;
    ans.push_back(res);
    for (int c = 1; c < r; c++)
    {
        res = res * (r - c);
        res = res / (c);
        ans.push_back(res);
    }
    return ans;
}
vector<vector<long long int>> printPascal(int n)
{
    // Write your code here.
    vector<vector<long long int>> ans;
    for (long long int i = 1; i <= n; i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}