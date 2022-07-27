#include <bits/stdc++.h>
using namespace std;

int solve(int k, int n, vector<vector<int>> &dp)
{
    if (k == 1)
        return n;
    if (n == 0 or n == 1)
        return n;
    if (dp[k][n] != -1)
        return dp[k][n];
    int ans = INT_MAX;
    int l = 1;
    int h = n;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        int axe_break = solve(k - 1, mid - 1, dp);
        int axe_not_break = solve(k, n - mid, dp);

        int temp = 1 + max(axe_break, axe_not_break);
        if (axe_not_break > axe_break)
        {
            l = mid + 1;
        }
        else
            h = mid - 1;
        ans = min(ans, temp);
    }
    return dp[k][n] = ans;
}
int cutLogs(int k, int n)
{
    // Write your code here.
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    return solve(k, n, dp);
}
