#include <bits/stdc++.h>
using namespace std;

bool canStudy(vector<int>&time,int n,long long mid){
    int count = 1;long long t=0;
    for(int i=0;i<time.size();i++){
        if(time[i]>mid)return false;
        if(time[i]+t>mid){
            count++;
            t=time[i];
        }
        else t+=time[i];
    }
    if(count > n)return false;
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long ans,sum=0;
    for(auto it:time)sum+=it;
    long long low = time[0],high = sum;
    while(low <= high){
        long long mid = (low+high)/2;
        if(canStudy(time,n,mid)){
            high = mid-1;
        }
        else low = mid + 1;
    }
    return low;
}