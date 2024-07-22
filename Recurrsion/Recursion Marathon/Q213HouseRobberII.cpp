class Solution {
public:

    int solve(vector<int>& nums, int s, int e){
        //base case
        if(s>e)
            return 0;
        
        //chori karlo -->ith index par
        int option1 = nums[s] + solve(nums, s+2, e);

        //chori karlo -->ith index par
        int option2 = 0 + solve(nums, s+1, e);

        int finalAns = max(option1, option2);
 
        return finalAns;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        //single element-->yahan par mein ne galti ki thi
        if(n == 1){
            return nums[0];
        }
        int option1 = solve(nums, 0, n-2);
        int option2 = solve(nums, 1 , n-1);

        int ans = max(option1, option2);
        return ans;
    }

};