#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool areAnagram(string &str1, string &str2)
{
    // Write your code here.
    if (str1.size() != str2.size())
        return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}
bool areAnagram(string &str1, string &str2)
{
    // Write your code here.
    if (str1.size() != str2.size())
        return false;
    vector<int> ans(26, 0);
    int n = str1.size();
    for (int i = 0; i < n; i++)
    {
        ans[str1[i] - 'a']++;
        ans[str2[i] - 'a']--;
    }
    for (int x : ans)
    {
        if (x != 0)
            return false;
    }
    return true;
}