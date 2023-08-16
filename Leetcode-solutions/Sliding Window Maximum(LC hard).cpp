class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> q;
        vector<int> ans;
        int i=0;
        int j=0;
        while(j<n) {
            int curElement=nums[j];
            while(!q.empty() && q.back()<curElement) {
                q.pop_back();
            }
            q.push_back(curElement);
            if(j-i+1<k) {
                j++;
            } else {
                int largestInWindow=q.front();
                ans.push_back(largestInWindow);
                if(q.front()==nums[i]) {
                    q.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
