//TLE//

class Solution {
public:

    int solve(vector<int>& coins, int amount){
        //base case
        if(amount==0)
            return 0; //0 amount create karne ke liye 

        int minCoinAns = INT_MAX;

        //hr amount ke liye poore coins ke arr ko travel karunga

        for(int i=0; i<coins.size(); i++){
            int amt = amount;
            int coin = coins[i];
            //if coin value > amount value, no need to call recursive cll
            //if coin value <= call recursive value
            if(coin <= amount){
                //1 coin toh use ho gaya , amount becomes amount-coins
                //baki recursion sambhal lega
                int recursionAns = solve(coins, amount-coin);
                //ho sakta hai recusionAns valid b ho sakta hai and non valid bhi 
                //invalid case -->recursionAns-->INT_MAX;
                //valid -->recursionAns -->not equal to INT_MAX
                if(recursionAns!=INT_MAX){
                    int coinUsed= 1+recursionAns;
                    minCoinAns = min(minCoinAns, coinUsed);
                }

            }
        }

        return minCoinAns;
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        if(ans== INT_MAX)
            return -1;
        return ans;
    }
};