#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int>ans;
    deque<int>q;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(!q.empty() and q.front() == i-k)q.pop_front();
        while(!q.empty() and nums[q.back()]<nums[i])q.pop_back();
        q.push_back(i);
        if(i>=k-1) ans.push_back(nums[q.front()]);
    }
    return ans;
}