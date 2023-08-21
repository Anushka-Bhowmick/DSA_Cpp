/*
Contributed by Supratim Bhattacharjee

Arithmetic Slices(LC Medium)
Dynamic programming
Time complexity:- O(n)
Space Complexity:- O(1)
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return 0;
        int diff=nums[1]-nums[0];
        int ans=0;
        int count=1;
        for(int i=2;i<n;i++) {
            int curDiff=nums[i]-nums[i-1];
            if(curDiff==diff) {
                ans+=count;
                count++;
            } else {
                count=1;
            }
            diff=curDiff;
        }
        return ans;
    }
};
