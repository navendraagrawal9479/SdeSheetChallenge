#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>>ans;
    vector<int>currinterval;
    sort(intervals.begin(),intervals.end());
    currinterval=intervals[0];
    for(int i=1;i<intervals.size();i++){
        if(currinterval[1]<intervals[i][0]){
            ans.push_back(currinterval);
            currinterval=intervals[i];
        }
        else{
            currinterval[1]=max(currinterval[1],intervals[i][1]);
        }
    }
    ans.push_back(currinterval);
    return ans;
}
