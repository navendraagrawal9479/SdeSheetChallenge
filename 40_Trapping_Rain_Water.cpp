#include <bits/stdc++.h>
using namespace std;

long getTrappedWater(long *arr, int n){
    int l=0,r=n-1;
    long leftmax=INT_MIN,rightmax=INT_MIN,rain=0;
    while(l<r){
        if(arr[l]<=arr[r]){
            if(leftmax<=arr[l]){
                leftmax=arr[l];
            }
            else{
                rain+=leftmax-arr[l];
            }
            l++;
        }
        else{
            if(rightmax<=arr[r]){
                rightmax=arr[r];
            }
            else{
                rain+=rightmax-arr[r];
            }
            r--;
        }
    }
    return rain;
}