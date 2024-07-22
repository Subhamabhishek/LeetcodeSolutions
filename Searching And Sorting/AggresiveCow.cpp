bool isPossibleSolution(vector<int>&stall, int k, int mid){
    int c=1;
    int pos=stall[0];
    for(int i=1; i<stall.size(); i++){
        if(stall[i]-pos >= mid){
            c++;
            pos=stall[i];
            
        }
        if(c==k)
            return true;
    }
    return false;
}


int solve(vector<int> &stall, int n, int k){
        sort(stall.begin(), stall.end());
        int start =0; 
        int end= stall[stall.size()-1]-stall[0];
        int ans=-1;
        while(start<=end){
            int mid= (start+end)>>1;
            if(isPossibleSolution(stall,k,mid)){
                ans=mid;
                start=mid+1;
            }
            else    
                end=mid-1;
        }
        return ans;
}