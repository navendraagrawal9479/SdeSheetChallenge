#include <bits/stdc++.h>
using namespace std;


double findNthRootOfM(int n, long long m) {
	// Write your code here.
	double p=1.0/n;
    double no = double(m);
    return pow(no,p);
}