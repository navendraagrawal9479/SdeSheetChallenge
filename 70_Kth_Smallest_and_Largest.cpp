#include <bits/stdc++.h>
using namespace std;

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	priority_queue<int>max;
    priority_queue<int,vector<int>,greater<int>>min;
    for(int i=0;i<n;i++){
        if(max.size()>=k and max.top()>arr[i]){
            max.pop();
            max.push(arr[i]);
        }
        else if(max.size()<k){
            max.push(arr[i]);
        }
        if(min.size()>=k and min.top()<arr[i]){
            min.pop();
            min.push(arr[i]);
        }
        else if(min.size()<k){
            min.push(arr[i]);
        }
    }
    return {max.top(),min.top()};
}