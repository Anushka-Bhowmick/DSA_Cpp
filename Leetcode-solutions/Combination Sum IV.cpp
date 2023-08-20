/*
Contributed by Supratim Bhattacharjee

Time complexity: O(target*n)
Space complexity: O(targe)
*/

//Memoization
class Solution {
public:
    int numWays(vector<int>& nums, vector<int>& dp, int target) {
        if(target==0)
            return dp[0]=1;

        if(dp[target]!=-1)
            return dp[target];

        int ans=0;
        for(int i=0;i<nums.size();i++) {
            if(target-nums[i]>=0)
                ans+=numWays(nums,dp,target-nums[i]);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return numWays(nums,dp,target);
    }
};


//Tabulation
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,0);
        dp[0]=1;

        for(int i=1;i<=target;i++) {
            long long curAns=0;
            for(int j=0;j<nums.size();j++) {
            if(i-nums[j]>=0)
                curAns+=dp[i-nums[j]];
            }
            dp[i]=curAns;
        }

        return dp[target];
    }
};
