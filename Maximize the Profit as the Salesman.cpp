/*
Contributed by Supratim Bhattacharjee

LC Weekly Contest 359(Problem C)
C++ DP+Binary Search Solution
Time Complexity:- O(mlogm)
Space Complexity:- O(m)
*/

class Solution {
public:
    int maxProfit(int i, vector<vector<int>>& offers, vector<int>& dp) {
        if(i==offers.size()) {
            return 0;
        }
        
        if(dp[i]!=-1) {
            return dp[i];
        }
        
        int low=i+1;
        int high=offers.size()-1;
        int indx=-1;

        while(low<=high) {
            int mid=low+(high-low)/2;
            if(offers[mid][0]<=offers[i][1]) {
                low=mid+1;
            } else {
                indx=mid;
                high=mid-1;
            }
        }
        int take=offers[i][2];
        if(indx!=-1)
            take+=maxProfit(indx,offers,dp);
        int notTake=maxProfit(i+1,offers,dp);
        
        return dp[i]=max(take, notTake);
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m=offers.size();
        sort(offers.begin(),offers.end());
        vector<int> dp(m,-1);
    
        return maxProfit(0, offers, dp);    
    }
};
