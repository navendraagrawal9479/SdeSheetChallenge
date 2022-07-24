#include <bits/stdc++.h>
using namespace std;

class Median
{
    priority_queue<int, vector<int>, greater<int>> q1;
    priority_queue<int> q2;

public:
    void addElement(int num)
    {
        if (q2.empty() or q2.top() > num)
        {
            q2.push(num);
        }
        else
        {
            q1.push(num);
        }
        if (q1.size() > q2.size() + 1)
        {
            q2.push(q1.top());
            q1.pop();
        }
        else if (q1.size() + 1 < q2.size())
        {
            q1.push(q2.top());
            q2.pop();
        }
    }
    int findMedian()
    {
        if (q1.size() == q2.size())
        {
            return (q1.top() + q2.top()) / 2;
        }
        return q1.size() > q2.size() ? q1.top() : q2.top();
    }
};

vector<int> findMedian(vector<int> &arr, int n)
{
    // Write your code here
    vector<int> ans;
    Median m;
    for (auto it : arr)
    {
        m.addElement(it);
        ans.push_back(m.findMedian());
    }
    return ans;
}
