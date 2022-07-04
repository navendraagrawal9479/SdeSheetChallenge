#include <bits/stdc++.h>
using namespace std;

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    priority_queue<pair<int,int>>q;
    unordered_map<int,int>m;
    for(auto it:arr){
        m[it]++;
    }
    for(auto it:m){
        q.push({it.second,it.first});
    }
    vector<int>ans(k);
    for(int i=k-1;i>=0;i--){
        ans[i]=q.top().second;
        q.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}