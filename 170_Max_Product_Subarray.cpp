#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &arr, int n)
{
    // Write your code here
    int ans = arr[0];
    int ma = arr[0];
    int mi = arr[0];
    for (int i = 1; i < n; i++)
    {
        int tempmini = mi;
        int tempmaxi = ma;
        mi = min(tempmini * arr[i], min(tempmaxi * arr[i], arr[i]));
        ma = max(tempmini * arr[i], max(tempmaxi * arr[i], arr[i]));
        ans = max(ans, ma);
    }
    return ans;
}
