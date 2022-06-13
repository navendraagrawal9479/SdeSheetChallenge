#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> arr, int n, int k)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> sum_triplet;
    for (int i = 0; i < n - 2; i++)
    {
        if (i == 0 or (i > 0 and arr[i] != arr[i - 1]))
        {
            int sum = k - arr[i];
            int l = i + 1, h = n - 1;
            while (l < h)
            {
                if (sum == arr[l] + arr[h])
                {
                    sum_triplet.push_back({arr[i], arr[l], arr[h]});
                    while (l < h and arr[h] == arr[h - 1])
                        h--;
                    while (l < h and arr[l] == arr[l + 1])
                        l++;
                    l++;
                    h--;
                }
                else if (arr[l] + arr[h] < sum)
                {
                    l++;
                }
                else
                    h--;
            }
        }
    }
    return sum_triplet;
}