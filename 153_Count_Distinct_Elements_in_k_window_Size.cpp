#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	unordered_map<int,int>m;
    for(int i=0;i<k;i++){
        m[arr[i]]++;
    }
    int n=arr.size();
    vector<int>ans;
    ans.push_back(m.size());
    for(int i=k;i<n;i++){
        if(m[arr[i-k]]==1)m.erase(arr[i-k]);
        else m[arr[i-k]]--;
        m[arr[i]]++;
        ans.push_back(m.size());
    }
    return ans;
}