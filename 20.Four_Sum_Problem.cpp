#include <bits/stdc++.h> 
using namespace std;
string fourSum(vector<int> arr, int target, int n) {
    unordered_map<int,pair<int,int>>m;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            m[arr[i]+arr[j]]={i,j};
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int sum=target-arr[i]-arr[j];
            if(m.find(sum)!=m.end()){
                if(m[sum].first!=i and m[sum].second!=i and m[sum].first!=j and m[sum].second!=j){
                    return "Yes";
                }
            }
        }
    }
    return "No";
}
