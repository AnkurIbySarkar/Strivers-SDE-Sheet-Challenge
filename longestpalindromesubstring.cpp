#include <iostream>
using namespace std;
int check(string &s, int L, int R)
{
    while (L >= 0 && R < s.size() && s[L] == s[R])
    {
        L--;
        R++;
    }
    return R - L - 1;
}
string longestPalinSubstring(string str)
{
    // Write your code here.
    int ans = 0, st = 0;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        int len1 = check(str, i, i);
        int len2 = check(str, i, i + 1);
        int len = max(len1, len2);
        if (len > ans)
        {
            ans = len;
            st = i - (len - 1) / 2;
        }
    }
    return str.substr(st, ans);
}