#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int>nextGreater(n);
    stack<int>s;
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            nextGreater[i] = -1;
        }
        else if(s.top()<=arr[i]){
            while(!s.empty() and s.top()<=arr[i]){
                s.pop();
            }
            if(s.empty()){
                nextGreater[i] = -1;
            }
            else nextGreater[i] = s.top();
        }
        else nextGreater[i] = s.top();
        s.push(arr[i]);
    }
    return nextGreater;
}