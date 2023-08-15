//Memoization
class Solution {
public:
    int minimumCoins(int amount, vector<int>& coins, vector<int>& dp) {
        if(amount==0)
            return 0;
        if(dp[amount]!=-1)
            return dp[amount];
        int ans=10001;
        for(int i=0;i<coins.size();i++) {
            if(amount-coins[i]>=0) {
                ans=min(ans,minimumCoins(amount-coins[i],coins,dp)+1);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int answer=minimumCoins(amount, coins, dp);
        return answer==10001?-1:answer;
    }
};

//Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        for(int i=1;i<=amount;i++) {
            int ans=10001;
            for(int j=0;j<coins.size();j++) {
                if(i-coins[j]>=0) {
                    ans=min(ans,dp[i-coins[j]]+1);
                }
            }
            dp[i]=ans;
        }
        return dp[amount]==10001?-1:dp[amount];
    }
};
