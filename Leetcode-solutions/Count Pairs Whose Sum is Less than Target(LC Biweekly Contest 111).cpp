//Sorting + Binary search 
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++) {
            int l=i;
            int h=n-1;
            int cur=0;
            while(l<=h) {
                int mid=(l+h)/2;
                if(nums[i]+nums[mid]>=target) {
                    h=mid-1;
                } else {
                    cur=max(mid-i,cur);
                    l=mid+1;
                }
            }
            ans+=cur;
        }
        return ans;
    }
};

//Two Pointer
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int i=0;
        int j=n-1;

        while(i<j) {
            if(nums[i]+nums[j]>=target) {
                j--;
            } else {
                ans+=j-i;
                i++;
            }
        }

        return ans;
    }
};
