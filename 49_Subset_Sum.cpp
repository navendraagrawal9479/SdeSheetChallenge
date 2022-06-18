#include <bits/stdc++.h>
using namespace std;

void solve(int i,int sum,vector<int>&num,vector<int>&ans){
    if(i==num.size()){
        ans.push_back(sum);
        return;
    }
    solve(i+1,sum,num,ans);
    solve(i+1,sum+num[i],num,ans);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int>ans;
    solve(0,0,num,ans);
    sort(ans.begin(),ans.end());
    return ans;
}