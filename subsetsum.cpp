#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void f(int i, vector<int> &num, vector<int> &ans, int sum)
{
    if (i == num.size())
    {
        ans.push_back(sum);
        return;
    }
    // don't take it
    f(i + 1, num, ans, sum);
    // take it
    f(i + 1, num, ans, sum + num[i]);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;

    f(0, num, ans, 0);

    sort(ans.begin(), ans.end()); // sort the ans vector
    return ans;
    /*
    TC: O(2^n)
    SC: O(2^n)
    */
}