#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> pwset(vector<int> nums)
{
    // Write your code here
    vector<vector<int>> powerSet;
    int n = nums.size();
    int subsets = 1 << n; // Number of subsets = 2^n

    for (int i = 0; i < subsets; i++)
    {
        vector<int> subset;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            { // Checking if jth bit is set in i
                subset.push_back(nums[j]);
            }
        }
        powerSet.push_back(subset);
    }

    return powerSet;
}