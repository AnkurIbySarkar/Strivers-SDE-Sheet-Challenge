#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPossible(vector<int> &positions, int cows, int distance)
{
    int count = 1;
    int lastPosition = positions[0];
    for (int i = 1; i < positions.size(); i++)
    {
        if (positions[i] - lastPosition >= distance)
        {
            count++;
            lastPosition = positions[i];
        }
        if (count == cows)
        {
            return true;
        }
    }
    return false;
}

int chessTournament(vector<int> &positions, int n, int cows)
{
    sort(positions.begin(), positions.end());

    int maxDistance = 0;

    for (int distance = 1; distance <= positions[n - 1] - positions[0]; distance++)
    {
        if (isPossible(positions, cows, distance))
        {
            maxDistance = distance;
        }
    }

    return maxDistance;
}
bool isPossible(vector<int> &positions, int cows, int distance)
{
    int count = 1;
    int lastPosition = positions[0];
    for (int i = 1; i < positions.size(); i++)
    {
        if (positions[i] - lastPosition >= distance)
        {
            count++;
            lastPosition = positions[i];
        }
        if (count == cows)
        {
            return true;
        }
    }
    return false;
}

int chessTournament(vector<int> &positions, int n, int cows)
{
    sort(positions.begin(), positions.end());

    int maxDistance = 0;

    int low = 0, high = positions[n - 1] - positions[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(positions, cows, mid))
        {
            maxDistance = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return maxDistance;
}
