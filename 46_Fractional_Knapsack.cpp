#include <bits/stdc++.h>
using namespace std;

static bool compare(pair<int,int>a,pair<int,int>b){
    double w1=(a.first);
    double w2=(b.first);
    double v1=(a.second);
    double v2=(b.second);
    return v1/w1>v2/w2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    int totalWeight=0;
    double maxValue=0;
    sort(items.begin(),items.end(),compare);
    for(int i=0;i<n;i++){
        if(totalWeight+items[i].first<w){
            maxValue+=double(items[i].second);
            totalWeight+=items[i].first;
        }
        else{
            maxValue+=(w-totalWeight)*double(items[i].second)/double(items[i].first);
            break;
        }
    }
    return maxValue;
}