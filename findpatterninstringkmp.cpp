#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool findPattern(string p, string s)
{
    // Write your code here.
    int ssize = s.size();
    int psize = p.size();
    for (int i = 0; i < ssize - psize + 1; i++)
    {
        if (s.substr(i, psize) == p)
        {
            return true;
        }
    }
    return false;
}
void computeLPS(string &p, vector<int> &lps)
{
    int psize = p.size();
    int len = 0; // Length of the previous longest proper prefix which is also a suffix

    lps.resize(psize);

    int i = 1;
    while (i < psize)
    {
        if (p[i] == p[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool findPattern(string &p, string &s)
{
    int ssize = s.size();
    int psize = p.size();

    vector<int> lps;
    computeLPS(p, lps);

    int i = 0; // Index for string s
    int j = 0; // Index for pattern p

    while (i < ssize)
    {
        if (p[j] == s[i])
        {
            j++;
            i++;
        }

        if (j == psize)
        {
            return true; // Pattern found
        }
        else if (i < ssize && p[j] != s[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return false; // Pattern not found
}