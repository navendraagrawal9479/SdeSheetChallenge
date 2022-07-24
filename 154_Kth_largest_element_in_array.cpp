#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
    priority_queue<int,vector<int>,greater<int>>q;
    for(auto it:arr){
        q.push(it);
        if(q.size()>K)q.pop();
        
    }
    return q.top();
}