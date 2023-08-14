class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int allXor=0;
        vector<int> ans(2,0);
        int n=nums.size();

        for(int i=0;i<n;i++) {
            allXor^=nums.at(i);
        }

        int rightMostSetBitNum=1;
        int diff=0;
        
        for(int i=0;i<32;i++) {
            if((rightMostSetBitNum<<i)&allXor) {
                diff=rightMostSetBitNum<<i;
                break;
            }
        }

        for(auto num: nums) {
            if(diff&num) {
                ans[0]^=num;
            } else {
                ans[1]^=num;
            }
        }

        return ans;
    }
};
