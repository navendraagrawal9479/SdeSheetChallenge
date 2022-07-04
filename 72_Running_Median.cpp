#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int,vector<int>,greater<int>>q2;
    priority_queue<int>q1;
    
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(q1.empty() or q1.top()>num){
            q1.push(num);
        }
        else{
            q2.push(num);
        }
        
        if(q1.size()>q2.size()+1){
            q2.push(q1.top());
            q1.pop();
        }
        else if(q2.size()>q1.size()+1){
            q1.push(q2.top());
            q2.pop();
        }
    }
    
    int findMedian() {
        if(q1.size()==q2.size())return(q1.top()+q2.top())/2;
        else return q1.size()>q2.size()?q1.top():q2.top();
    }
};

void findMedian(int *arr, int n)
{
    MedianFinder h;
    for(int i=0;i<n;i++){
        h.addNum(arr[i]);
        cout<<h.findMedian()<<" ";
    }
    cout<<endl;
}