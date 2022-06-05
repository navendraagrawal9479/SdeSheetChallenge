#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices){
    int maxprofit=0,mini=prices[0];
    for(int i=0;i<prices.size();i++){
        mini=min(mini,prices[i]);
        maxprofit=max(maxprofit,prices[i]-mini);
    }
    return maxprofit;
}