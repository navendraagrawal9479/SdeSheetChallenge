#include <bits/stdc++.h> 
#include <vector>
using namespace std;

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int low=0,high=m*n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(mat[mid/n][mid%n]==target)return true;
        else if(mat[mid/n][mid%n]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}