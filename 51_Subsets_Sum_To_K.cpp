#include <bits/stdc++.h>
using namespace std;

void solve(int i,int sum,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans){
    if(i==arr.size()){
        if(sum==0){
            ans.push_back(ds);
        }
        return;
    }
    ds.push_back(arr[i]);
    solve(i+1,sum-arr[i],arr,ds,ans);
    ds.pop_back();
    solve(i+1,sum,arr,ds,ans);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int>ds;
    vector<vector<int>>ans;
    solve(0,k,arr,ds,ans);
    return ans;
}