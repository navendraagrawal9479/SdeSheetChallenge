#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int l = 0, h = s.size() - 1;
    while (l < h)
    {
        if (s[l] != s[h])
            return false;
        l++;
        h--;
    }
    return true;
}
int partition(int i, int n, string str, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int mini = INT_MAX;
    string temp = "";
    for (int j = i; j < n; j++)
    {
        temp += str[j];
        if (isPalindrome(temp))
        {
            int cost = 1 + partition(j + 1, n, str, dp);
            mini = min(mini, cost);
        }
    }
    return dp[i] = mini;
}
int palindromePartitioning(string str)
{
    // Write your code here
    vector<int> dp(str.size(), -1);
    return partition(0, str.size(), str, dp) - 1;
}
