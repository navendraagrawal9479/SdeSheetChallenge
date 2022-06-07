#include <bits/stdc++.h> 
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]=1;
    }
    int longest=0;
    for(auto it:arr){
        if(m.find(it-1)==m.end()){
            int num=it;
            int cnt=1;
            while(m.find(num+1)!=m.end()){
                num++;
                cnt++;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;
}