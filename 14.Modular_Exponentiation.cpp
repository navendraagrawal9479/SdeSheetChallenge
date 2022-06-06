int modularExponentiation(int x, int n, int m) {
	long long ans=1;
    int nn=n;
    long long xx=x;
    while(nn>0){
        if(nn%2==0){
            xx=(xx%m*xx%m)%m;
            nn=nn/2;
        }
        else{
            ans=(ans*xx%m)%m;
            nn=nn-1;
        }
    }
    return ans;
}