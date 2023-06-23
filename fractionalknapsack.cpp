#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comparision(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.second / (double)a.first; // value/weight
    double r2 = (double)b.second / (double)b.first;
    return r1 > r2;
}
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), comparision);
    int currweight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currweight + items[i].first <= w)
        {
            currweight += items[i].first;
            finalvalue += items[i].second;
        }
        else
        {
            int remain = w - currweight;
            finalvalue += ((double)items[i].second / (double)items[i].first) * (double)remain;
            break;
        }
    }
    return finalvalue;
}
