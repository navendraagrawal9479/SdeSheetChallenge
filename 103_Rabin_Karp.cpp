#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
const int base = 31;
const int q = 29;
void rabinkarp(string &pattern, string &text, vector<int> &ans)
{
    int j;
    int h = 1;
    int p = 0;
    int t = 0;
    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i < m - 1; i++)
        h = (h * base) % q;

    for (int i = 0; i < m; i++)
    {
        p = (base * p + pattern[i]) % q;
        t = (base * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                ans.push_back(i);
        }

        if (i < n - m)
        {
            t = t - h * text[i];
            t = (base * t + text[i + m]) % q;

            if (t < 0)
                t = t + q;
        }
    }
}
vector<int> stringMatch(string &str, string &pat)
{
    vector<int> ans;
    rabinkarp(pat, str, ans);
    return ans;
}