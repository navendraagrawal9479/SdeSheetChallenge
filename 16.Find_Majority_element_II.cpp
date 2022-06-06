#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    int cnt1=0,cnt2=0,num1=INT_MIN,num2=INT_MIN,n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==num1)cnt1++;
        else if(arr[i]==num2)cnt2++;
        else if(cnt1==0){
            num1=arr[i];
            cnt1++;
        }
        else if(cnt2==0){
            num2=arr[i];
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0;
    cnt2=0;
    for(auto it:arr){
        if(it==num1)cnt1++;
        else if(it==num2)cnt2++;
    }
    if(cnt1>n/3 and cnt2>n/3)return {num1,num2};
    else if(cnt1>n/3)return {num1};
    else if(cnt2>n/3)return {num2};
    else return {};
}