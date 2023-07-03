#include <iostream>
#include <string>
using namespace std;
string writeAsYouSpeak(int n)
{
    // Write your code here.
    string ans = "1";
    if (n == 0)
        return ans;
    for (int i = 1; i < n; i++)
    {
        string temp = "";
        int cnt = 1;
        for (int j = 0; j < ans.length() - 1; j++)
        {
            if (ans[j] == ans[j + 1])
            {
                cnt++;
            }
            else
            {
                temp += (to_string(cnt) + ans[j]);
                cnt = 1;
            }
        }
        temp += to_string(cnt) + ans[ans.length() - 1];
        ans = temp;
    }
    return ans;
}