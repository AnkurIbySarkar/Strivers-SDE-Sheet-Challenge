#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    int ans = 1;
    int cnt = 1;
    int prev = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == prev + 1)
        {
            cnt++;
        }
        else if (arr[i] != prev)
        {
            cnt = 1;
        }
        prev = arr[i];
        ans = max(ans, cnt);
    }
    return ans;
}
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    unordered_set<int> hashset;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        hashset.insert(arr[i]);
    }

    for (auto num : hashset)
    {
        if (!hashset.count(num - 1))
        {
            int currStreak = 1;
            int currNum = num;

            while (hashset.count(currNum + 1))
            {
                currStreak++;
                currNum++;
            }

            ans = max(currStreak, ans);
        }
    }

    return ans;
}