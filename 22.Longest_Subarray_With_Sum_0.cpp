#include <bits/stdc++.h> 
using namespace std;
int LongestSubsetWithZeroSum(vector < int > arr) {
    unordered_map<int,int>m;
    int n=arr.size();
    int sum=0,maxcnt=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            maxcnt=i+1;
        }
        else{
            if(m.find(sum)!=m.end()){
                maxcnt=max(maxcnt,i-m[sum]);
            }
            else{
                m[sum]=i;
            }
        }
    }
    return maxcnt;
}