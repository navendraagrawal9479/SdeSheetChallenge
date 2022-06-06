#include <bits/stdc++.h> 
using namespace std;
int merge(vector<int> &arr,vector<int> &temp,int low,int mid,int high){
    int i=low,j=mid,k=low,cnt=0;
    for(i=low;i<mid;i++){
        while(j<=high and arr[i]>2*arr[j])j++;
        cnt+=j-mid;
    }
    j=mid;
    i=low;
    while(i<mid and j<=high){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    for(i=low;i<=high;i++){
        arr[i]=temp[i];
    }
    return cnt;
}
int mergesort(vector<int> &arr,vector<int> &temp,int low,int high){
    int inv=0;
    if(low<high){
        int mid=(low+high)/2;
        inv+=mergesort(arr,temp,low,mid);
        inv+=mergesort(arr,temp,mid+1,high);
        inv+=merge(arr,temp,low,mid+1,high);
    }
    return inv;
}
int reversePairs(vector<int> &arr, int n){
    vector<int>temp(n);
	return mergesort(arr,temp,0,n-1);
}