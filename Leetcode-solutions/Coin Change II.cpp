class Solution {
public:
    int helper(int amount,int i, vector<int>& coins, vector<vector<int>>& dp) {
        //Base cases
        if(amount<0) {
            return 0;
        }
        if(amount==0) {
            return dp[amount][i]=1;
        }
        if(i==0) {
            return dp[amount][i]=(amount%coins[0]==0);
        }

        //Memoization
        if(dp[amount][i]!=-1) {
            return dp[amount][i];
        }

        //Sub-problems generated
        int take=helper(amount-coins[i],i,coins,dp);
        int notTake=helper(amount,i-1,coins,dp);

        //Solving larger problem using smaller sub-problems
        return dp[amount][i]=take+notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n,-1));
        
        helper(amount,n-1,coins,dp);

        return dp[amount][n-1];
    }
};
