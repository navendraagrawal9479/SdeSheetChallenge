#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
	vector<int>ans(n);
	stack<int>s;
	for(int i=n-1;i>=0;i--){
		int curr=arr[i];
		while(!s.empty() and s.top()>=curr){
			s.pop();
		}
		if(s.empty()){
		    ans[i]=-1;
		}
		else{
		    ans[i]=s.top();
		}
		s.push(curr);
	}
	return ans;
}