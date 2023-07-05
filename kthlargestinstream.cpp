#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Kthlargest
{
public:
    int K;
    vector<int> arr;
    Kthlargest(int k, vector<int> &arr)
    {
        // Write your code here.
        this->K = k;
        this->arr = arr;
    }

    void add(int num)
    {
        // Write your code here.
        arr.push_back(num);
    }

    int getKthLargest()
    {
        // Write your code here.
        sort(arr.begin(), arr.end(), greater<int>());
        return arr[K - 1];
    }
};

class Kthlargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    vector<int> arr;
    Kthlargest(int k, vector<int> &arr)
    {
        // Write your code here.
        this->K = k;
        this->arr = arr;
        for (auto &num : arr)
        {
            pq.push(num);
            if (pq.size() > K)
            {
                pq.pop();
            }
        }
    }

    void add(int num)
    {
        // Write your code here.
        arr.push_back(num);
        pq.push(num);
        if (pq.size() > K)
        {
            pq.pop();
        }
    }

    int getKthLargest()
    {
        // Write your code here.
        return pq.top();
    }
};