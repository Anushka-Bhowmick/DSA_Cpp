class Solution {
public:
    bool partition(vector<int>& arr, int i, int n, vector<int>& dp) {
        //If i reaches n it means the array can be partitioned with all valid partitions which follows the conditions given in the question
        if(i==n)
            return true;
        //If answer memoized then just return the answer as overlapping subproblems exist
        if(dp[i]!=-1)
            return dp[i];
        //if two consecutive elements are same then check if valid partitioning can be achieved from i+2 to n-1
        if(i+1<n && arr[i+1]==arr[i]) {
            if(partition(arr,i+2,n,dp))
                return dp[i]=true;
        }
        //if three consecutive elements are same then check if valid partitioning can be achieved from i+3 to n-1
        if(i+1<n && i+2<n && arr[i+1]==arr[i] && arr[i+2]==arr[i]) {
            if(partition(arr,i+3,n,dp))
                return dp[i]=true;
        }
        //if three consecutive elements with adjacent difference with one then check if valid partitioning can be achieved from i+3 to n-1
        if(i+1<n && i+2<n && arr[i+1]==arr[i]+1 && arr[i+2]==arr[i]+2) {
            if(partition(arr,i+3,n,dp))
                return dp[i]=true;
        }
        //If none of the 3 conditions are matching then it is certain that the array can't be partitiond with the given conditions
        return dp[i]=false;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        // -1 -> Not yet solved
        // 0 -> no valid partitions possible till i to n-1
        // 1 -> valid partitions possible till i to n-1
        vector<int> dp(n,-1);
        partition(nums,0,nums.size(),dp);
        return dp[0];
    }
};
