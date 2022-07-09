#include <bits/stdc++.h>
using namespace std;

int largestRectangle(vector < int > & heights) {
     stack<int>s;
     int n = heights.size();
     int maxarea = 0;
     for(int i=0;i<=n;i++){
         while(!s.empty() and (i==n or heights[s.top()]>=heights[i])){
             int h = heights[s.top()];
             s.pop();
             int width;
             if(s.empty())width = i;
             else width = i - s.top() - 1;
             maxarea = max(maxarea,width*h);
         }
         s.push(i);
     }
     return maxarea;
 }