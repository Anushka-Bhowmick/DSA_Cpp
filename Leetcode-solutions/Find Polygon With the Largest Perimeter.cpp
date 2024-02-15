class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pref(n,0);
        long long ans=-1;
        sort(nums.begin(),nums.end());
        pref[0]=nums[0];
        for(int i=1;i<n;i++) {
            pref[i]=pref[i-1]+nums.at(i);
        }
        for(int i=2;i<n;i++) {
            if(nums[i]<pref[i-1]) {
                ans=max(nums[i]+pref[i-1],ans);
            }
        }
        return ans;
    }
};
