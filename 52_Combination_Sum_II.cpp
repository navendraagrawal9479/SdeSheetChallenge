#include <bits/stdc++.h>
using namespace std;

void solve(int ind,int sum,int k,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans){
    if(sum==k){
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<arr.size();i++){
        if(i!=ind and arr[i]==arr[i-1])continue;
        ds.push_back(arr[i]);
        solve(i+1,sum+arr[i],k,arr,ds,ans);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int k)
{
	vector<int>ds;
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    solve(0,0,k,arr,ds,ans);
    return ans;
}
