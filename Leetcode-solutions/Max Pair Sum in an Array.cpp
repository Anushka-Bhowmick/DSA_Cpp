class Solution {
public:
    int maxDigit(int num) {
        int maxValDigit=0;
        while(num) {
           maxValDigit=max(maxValDigit,num%10);
           num/=10;
        }
        return maxValDigit;
    }

    int maxSum(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        vector<int> accumulate(10,0);
        for(int i=0;i<n;i++) {
            int curDig=maxDigit(nums[i]);
            if(accumulate[curDig]==0) {
                accumulate[curDig]=nums[i];
            } else {
                ans=max(ans,accumulate[curDig]+nums[i]);
                accumulate[curDig]=max(accumulate[curDig],nums[i]);
            }
        }

        return ans;
    }
};
