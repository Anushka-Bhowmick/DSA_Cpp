class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        vector<int> prev(m+1,0);
        vector<int> cur(m+1,0); 

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(nums1[i-1]==nums2[j-1]) {
                    cur[j]=1+prev[j-1];
                    ans=max(cur[j],ans);
                }
            }
            prev=cur;
            for(int i=0;i<=m;i++) {
                cur[i]=0;
            }
        }
        
        return ans;
    }
};
