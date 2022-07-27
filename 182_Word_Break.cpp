#include <bits/stdc++.h>
using namespace std;

bool solve(vector<string> &arr, int n, string &target, unordered_map<string, int> &m)
{
    if (target.size() == 0)
        return 1;
    int size = target.size();
    if (m.find(target) != m.end())
        return m[target];
    for (int i = 1; i <= size; i++)
    {
        string s = target.substr(0, i);
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (s == arr[i])
            {
                flag = 1;
                break;
            }
        }
        string ss = target.substr(i, size - i);
        if (flag and solve(arr, n, ss, m))
        {
            return m[target] = 1;
        }
    }
    return m[target] = 0;
}
bool wordBreak(vector<string> &arr, int n, string &target)
{
    // Write your code here.
    unordered_map<string, int> m;
    return solve(arr, n, target, m);
}