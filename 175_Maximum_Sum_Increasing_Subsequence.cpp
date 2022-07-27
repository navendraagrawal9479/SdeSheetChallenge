#include <bits/stdc++.h>
using namespace std;

int solve(int i, int prev, int n, vector<int> &rack, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;
    if (dp[i][prev + 1] != -1)
        return dp[i][prev + 1];
    int not_take = solve(i + 1, prev, n, rack, dp);
    int take = INT_MIN;
    if (prev == -1 or rack[i] > rack[prev])
    {
        take = rack[i] + solve(i + 1, i, n, rack, dp);
    }
    return dp[i][prev + 1] = max(take, not_take);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(0, -1, n, rack, dp);
}