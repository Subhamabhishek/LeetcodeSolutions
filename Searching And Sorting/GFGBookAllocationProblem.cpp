
bool isPossibleSolution(int a[], int n, int k, int mid){
    int pageSum=0;
    int c=1;

    for(int i=0; i<n; i++){
        if(a[i]>mid) return false;

        if(a[i]+pageSum > mid){
            c++;
            pageSum=a[i];

            if(c>k) return false;
        }

        else 
            pageSum+=a[i];
        
    }

    return true;
}
int minTime(int a[], int n, int k){
    int start=0;
    int end=accumulate(a, a+n, 0);
    
    int ans=-1;

    while(start<=end){
        int mid = start + (end-start)>>1;
        if(isPossibleSolution(a,n,k,mid)){
            ans=mid;
            end=mid-1;
        }
        else
            start= mid+1;
    }
    return ans;
}