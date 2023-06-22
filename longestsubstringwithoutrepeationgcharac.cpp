#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int uniqueSubstrings(string input)
{
    // Write your code here
    int ans = INT_MIN;
    int n = input.size();
    if (input.size() == 0)
        return 0;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> st;
        for (int j = i; j < n; j++)
        {
            if (st.find(input[j]) != st.end())
            {
                ans = max(ans, j - i);
                break;
            }
            st.insert(input[j]);
        }
    }
    return ans;
}
int uniqueSubstrings(string input)
{
    // Write your code here
    int ans = INT_MIN;
    int n = input.size();
    unordered_set<char> st;
    if (input.size() == 0)
        return 0;
    int l = 0;
    for (int r = 0; r < n; r++)
    {
        if ((st.find(input[r]) != st.end()))
        {
            while (l < r && st.find(input[r]) != st.end())
            {
                st.erase(input[l]);
                l++;
            }
        }
        st.insert(input[r]);
        ans = max(ans, r - l + 1);
    }
    return ans;
}