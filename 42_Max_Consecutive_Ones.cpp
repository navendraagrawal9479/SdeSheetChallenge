#include <bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr, int n, int k)
{
    // Write your code here.
    int maxlen = 0, K = k, i = 0, j = 0;
    while (i < n and j < n)
    {
        if (arr[j] == 1)
        {
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        else
        {
            if (K > 0)
            {
                K--;
                maxlen = max(maxlen, j - i + 1);
                j++;
            }
            else
            {
                if (arr[i] == 0)
                {
                    if (K < k)
                        K++;
                }
                i++;
            }
        }
    }
    return maxlen;
}
