////TLE/////

class Solution {
public:
    int solve(vector<int>&nums, int n, int i){
        if(i>=n)
            return 0;

        //include case
        int includeAns = nums[i]+solve(nums, n, i+2);
        //exclude case
        int excludeAns = 0 + solve(nums, n, i+1); //initially 0 hoga uske pass toh i+1 house chori karn eke bad add hoga 
        int finalAns = max(includeAns,excludeAns);
        return finalAns;

    } 
    int rob(vector<int>& nums) {
        int index=0;
        int ans= solve(nums,nums.size(),index);
        return ans;        
    }
};