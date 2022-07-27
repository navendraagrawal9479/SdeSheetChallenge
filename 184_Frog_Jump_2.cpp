#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define m 1000000007
 
int solve(int n,int k,vector<int>&height,vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int minEnergy=INT_MAX;
    for(int j=1;j<=k;j++){
        if(n-j>=0){
            int jump=solve(n-j,k,height,dp)+abs(height[n]-height[n-j]);
            minEnergy=min(minEnergy,jump);
        }
    }
    return dp[n]=minEnergy;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>height(n);
    for(int i=0;i<n;i++)cin>>height[i];
    vector<int>dp(n,-1);
    cout<<solve(n-1,k,height,dp);
 
    return 0;
}