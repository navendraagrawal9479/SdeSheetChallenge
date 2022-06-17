#include <bits/stdc++.h>
using namespace std;

static bool compare(vector<int>a,vector<int>b){
    return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int maxDeadline=0;
    for(int i=0;i<jobs.size();i++){
        maxDeadline=max(maxDeadline,jobs[i][0]);
    }
    int n=maxDeadline,maxProfit=0;
    vector<int>profits(n+1,-1);
    sort(jobs.begin(),jobs.end(),compare);
    for(int i=0;i<jobs.size();i++){
        int profit=jobs[i][1];
        int index=jobs[i][0];
        for(int j=index;j>0;j--){
            if(profits[j]==-1){
                profits[j]=profit;
                maxProfit+=profit;
                break;
            }
        }
    }
    return maxProfit;
}
