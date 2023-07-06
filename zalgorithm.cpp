#include <iostream>
#include <string>
#include <vector>
using namespace std;
int zAlgorithm(string s, string p, int n, int m)
{
    int cnt = 0;
    int n = s.length();
    int m = p.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (s[i + j] != p[j])
                break;
        }

        if (j == m)
            cnt++;
    }

    return cnt;
}
int zAlgorithm(string s, string p, int n, int m)
{
    // Write your code here
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.substr(i, m) == p)
        {
            cnt++;
        }
    }
    return cnt;
}
vector<int> buildPrefixTable(string p)
{
    int m = p.length();
    vector<int> prefixTable(m);

    int i = 0, j = 1;
    while (j < m)
    {
        if (p[i] == p[j])
        {
            prefixTable[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if (i != 0)
                i = prefixTable[i - 1];
            else
                j++;
        }
    }

    return prefixTable;
}

int zAlgorithm(string s, string p, int n, int m)
{
    // Write your code here
    int cnt = 0;

    vector<int> prefixTable = buildPrefixTable(p);

    int i = 0, j = 0;
    while (i < n)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;

            if (j == m)
            {
                cnt++;
                j = prefixTable[j - 1];
            }
        }
        else
        {
            if (j != 0)
                j = prefixTable[j - 1];
            else
                i++;
        }
    }

    return cnt;
}