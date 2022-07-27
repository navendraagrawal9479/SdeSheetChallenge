#include <bits/stdc++.h>
using namespace std;

int solve(int i, int n, int l, vector<int> &price, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        return (l / (i + 1)) * price[i];
    }
    if (dp[i][l] != -1)
        return dp[i][l];
    int not_take = solve(i - 1, n, l, price, dp);
    int take = INT_MIN;
    if ((i + 1) <= l)
        take = price[i] + solve(i, n, l - (i + 1), price, dp);
    return dp[i][l] = max(take, not_take);
}

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(price.size(), vector<int>(n + 1, -1));
    return solve(price.size() - 1, price.size(), n, price, dp);
}