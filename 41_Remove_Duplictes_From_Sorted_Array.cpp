#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    int index=0,i=0;
    while(i<arr.size()){
        arr[index++]=arr[i++];
        while(i<arr.size() and arr[i]==arr[i-1]){
            i++;
        }
    }
    return index;
}