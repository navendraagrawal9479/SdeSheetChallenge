#include <bits/stdc++.h>
using namespace std;

static bool compare(pair<int,int>a,pair<int,int>b){
    if(a.second<b.second)return true;
    return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n=start.size();
    vector<pair<int,int>>activities(n);
    for(int i=0;i<n;i++){
        activities[i].first=start[i];
        activities[i].second=finish[i];
    }
    sort(activities.begin(),activities.end(),compare);
    int endTime=activities[0].second,maximumActivity=1;
    for(int i=1;i<n;i++){
        if(activities[i].first>=endTime){
            maximumActivity++;
            endTime=activities[i].second;
        }
    }
    return maximumActivity;
}