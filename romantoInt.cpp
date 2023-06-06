#include <iostream>
#include <unordered_map>
using namespace std;
int romantoint(string s)
{
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int result = 0;
    int n = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        int currentval = mp[s[i]];
        if (i < n - 1 && currentval < mp[s[i + 1]])
        {
            result -= currentval;
        }
        else
        {
            result += currentval;
        }
    }
    return result;
}