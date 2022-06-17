#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    int i=0;
    int j=1,platform=1,maxi=1;
    while(j<n){
        if(dt[i]>=at[j]){
            platform++;
            j++;
        }
        else{
            i++;
            platform--;
        }
        maxi=max(maxi,platform);
    }
    return maxi;
}