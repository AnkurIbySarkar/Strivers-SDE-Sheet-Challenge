#include <iostream>
using namespace std;
int compareVersions(string a, string b)
{
    // Write your code here
    int i = 0, j = 0, m = a.size(), n = b.size();
    long ans1 = 0, ans2 = 0;
    while (i < m || j < n)
    {
        while (i < m && a[i] != '.')
        {
            ans1 = ans1 * 10 + (a[i] - '0');
            i++;
        }
        while (j < n && b[j] != '.')
        {
            ans2 = ans2 * 10 + (b[j] - '0');
            j++;
        }
        if (ans1 < ans2)
        {
            return -1;
        }
        if (ans1 > ans2)
        {
            return 1;
        }
        i++;
        j++;
        ans1 = 0;
        ans2 = 0;
    }
    return 0;
}