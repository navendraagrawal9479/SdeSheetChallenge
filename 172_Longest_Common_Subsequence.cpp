#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (i == s.size() or j == t.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
        return dp[i][j] = 1 + solve(i + 1, j + 1, s, t, dp);
    else
        return dp[i][j] = max(solve(i + 1, j, s, t, dp), solve(i, j + 1, s, t, dp));
}

int lcs(string s, string t)
{
    // Write your code here
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    return solve(0, 0, s, t, dp);
}