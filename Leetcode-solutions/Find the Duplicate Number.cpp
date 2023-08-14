class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        int temp=fast;
        slow=nums[0];
        while(slow!=temp)
        {
            slow=nums[slow];
            temp=nums[temp];
        }
        return slow;
    }
};
