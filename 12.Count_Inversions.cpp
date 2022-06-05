#include <bits/stdc++.h> 
using namespace std;
long long merge(long long temp[],long long arr[],int low,int mid,int high){
    int i,j,k,inv=0;
    i=low;
    j=mid;
    k=low;
    while(i<mid and j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            inv+=mid-i;
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
    return inv;
}
long long mergesort(long long temp[],long long arr[],int low,int high){
    long long inv=0;
    if(low<high){
        int mid=(low+high)/2;
        inv+=mergesort(temp,arr,low,mid);
        inv+=mergesort(temp,arr,mid+1,high);
        inv+=merge(temp,arr,low,mid+1,high);
    }
    return inv;
}
long long getInversions(long long *arr, int n){
    long long int temp[n];
    return mergesort(temp,arr,0,n-1);
}