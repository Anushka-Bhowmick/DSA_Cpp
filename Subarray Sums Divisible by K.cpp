class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> runningSumRem(k,0);
        int n=nums.size();
        int sum=0;
        runningSumRem[0]=1;
        for(int i=0;i<n;i++) {
            if(nums[i]>=0)
                sum+=nums[i];
            else {
                sum+=k-((-1)*nums[i]%k);
            }
            runningSumRem[sum%k]++;
        }
        int ans=0;
        for(int x: runningSumRem) {
            ans+=x*(x-1)/2;
        }

        return ans;
    }
};
