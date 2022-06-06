int findMajorityElement(int arr[], int n) {
	int cnt=0,el;
    for(int i=0;i<n;i++){
        if(cnt==0){
            el=arr[i];
        }
        if(el==arr[i]){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    cnt=0;
    for(int i=0;i<n;i++){
        if(el==arr[i])cnt++;
    }
    if(cnt>n/2)return el;
    return -1;
}