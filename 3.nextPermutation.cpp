#include <bits/stdc++.h> 
using namespace std;
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int i;
    for(i=n-2;i>=0;i--){
        if(permutation[i]<permutation[i+1]){
            break;
        }
    }
    if(i<0){
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }
    for(int j=n-1;j>i;j--){
        if(permutation[j]>permutation[i]){
            swap(permutation[i],permutation[j]);
            break;
        }
    }
    sort(permutation.begin()+i+1,permutation.end());
    return permutation;
}
