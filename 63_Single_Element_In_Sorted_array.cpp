#include <bits/stdc++.h>
using namespace std;

int uniqueElement(vector<int> arr, int n)
{
	int low=0,high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==arr[mid^1])low=mid+1;
        else high=mid-1;
    }
    return arr[low];
}
