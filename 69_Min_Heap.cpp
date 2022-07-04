#include <bits/stdc++.h>
using namespace std;

class heap{
    int size;
    int arr[100001];
public:
    heap(){
        size=0;
        arr[0]=-1;
    }
    void insert(int x){
        size++;
        arr[size]=x;
        int i=size;
        while(i>1){
            if(arr[i/2]>arr[i]){
                swap(arr[i/2],arr[i]);
                i=i/2;
            }
            else return;
        }
    }
    int pop(){
        if(size==0)return -1;
        int x=arr[1];
        swap(arr[1],arr[size]);
        size--;
        int i=1;
        while(i<=size){
            
            int leftind = 2*i;
            int rightind = 2*i +1;
            int smaller = i;
            if(leftind <= size && arr[leftind] < arr[smaller])
                smaller = leftind;
            
            if(rightind <= size && arr[smaller] > arr[rightind])
                smaller = rightind;
                
           if(i == smaller)break;
            
            swap(arr[i],arr[smaller]);
            i = smaller;
            
        }
        return x;
    }
};

vector<int> minHeap(int n, vector<vector<int>>& q) {
    heap h;
    vector<int>ans;
    for(auto it:q){
        if(it[0]){
            ans.push_back(h.pop());
        }
        else{
            h.insert(it[1]);
        }
    }
    return ans;
}
