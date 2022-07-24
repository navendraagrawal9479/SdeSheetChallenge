#include <bits/stdc++.h>
using namespace std;

class Kthlargest
{
    priority_queue<int, vector<int>, greater<int>> q;
    int k;

public:
    Kthlargest(int k, vector<int> &arr)
    {
        // Write your code here.
        this->k = k;
        for (auto it : arr)
        {
            q.push(it);
            if (q.size() > k)
                q.pop();
        }
    }

    void add(int num)
    {
        // Write your code here.
        q.push(num);
        if (q.size() > k)
            q.pop();
    }

    int getKthLargest()
    {
        // Write your code here.
        return q.top();
    }
};