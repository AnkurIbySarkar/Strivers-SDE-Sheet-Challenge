#include <iostream>
using namespace std;
string check(string &s, int L, int R)
{
    while (L >= 0 && R < s.size() && s[L] == s[R])
    {
        L--;
        R++;
    }
    return s.substr(L + 1, R - L - 1);
}
string longestPalinSubstring(string str)
{
    // Write your code here.
    string ans;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        string len1 = check(str, i, i);
        string len2 = check(str, i, i + 1);
        if (len1.size() > ans.size())
        {
            ans = len1;
        }
        if (len2.size() > ans.size())
        {
            ans = len2;
        }
    }
    return ans;
}