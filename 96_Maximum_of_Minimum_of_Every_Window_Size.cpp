#include <bits/stdc++.h>
using namespace std;

vector<int> maxMinWindow(vector<int> &a, int n)
{
    stack<int> s;
    vector<int> nextSmaller(n), prevSmaller(n), ans(n, -1e9);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() and a[s.top()] >= a[i])
            s.pop();
        if (s.empty())
            prevSmaller[i] = -1;
        else
            prevSmaller[i] = s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() and a[s.top()] >= a[i])
            s.pop();
        if (s.empty())
            nextSmaller[i] = n;
        else
            nextSmaller[i] = s.top();
        s.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        nextSmaller[i] = nextSmaller[i] - prevSmaller[i] - 1;
    }
    for (int i = 0; i < n; i++)
    {
        ans[nextSmaller[i] - 1] = max(a[i], ans[nextSmaller[i] - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    return ans;
}