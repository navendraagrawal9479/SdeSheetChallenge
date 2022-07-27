#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> prev(value + 1, 0), curr(value + 1, 0);
    for (int v = 0; v <= value; v++)
    {
        if (v % denominations[0] == 0)
            prev[v] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int v = 0; v <= value; v++)
        {
            long not_take = prev[v];
            long take = 0;
            if (denominations[i] <= v)
                take = curr[v - denominations[i]];
            curr[v] = take + not_take;
        }
        prev = curr;
    }
    return prev[value];
}