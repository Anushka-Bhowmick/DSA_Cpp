class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans=1;
        int n=arr.size();
        for(int i=n-1;i>=0;i--) {
            if(dp.find(arr[i]+difference)==dp.end()) {
                dp[arr[i]]=1;
            } else {
                dp[arr[i]]=dp[arr[i]+difference]+1;
            }
            ans=max(dp[arr[i]],ans);
        }
        return ans;
    }
};
