#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<int> prev(w + 1, 0), curr(w + 1, 0);
    for (int i = weights[0]; i <= w; i++)
        prev[i] = values[0];
    for (int i = 1; i < n; i++)
    {
        for (int W = 0; W <= w; W++)
        {
            int not_take = prev[W];
            int take = INT_MIN;
            if (weights[i] <= W)
                take = values[i] + prev[W - weights[i]];
            curr[W] = max(take, not_take);
        }
        prev = curr;
    }
    return prev[w];
}