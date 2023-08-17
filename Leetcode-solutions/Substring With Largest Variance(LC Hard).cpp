class Solution {
private:
    int maxSubArraySum(vector<int>& nums) {
        int countPos=0;
        int countNeg=0;
        bool negEncountered=false;
        int maxSum=INT_MIN;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]==+1)
                countPos++;
            else
                countNeg++;
            if(countNeg>0)
                maxSum=max(countPos-countNeg,maxSum);   
            else if(countNeg==0 && negEncountered)
                maxSum=max(countPos-1,maxSum);
            if(countNeg>countPos)
            {
                countPos=0;
                countNeg=0;
                negEncountered=true;
            }   
        }
        return maxSum;
    }
public:
    int largestVariance(string s) {
        unordered_set<int> isPresent;
        int n=s.size();
        int ans=0;
        vector<int> mark;

        for(int i=0;i<n;i++)
            isPresent.insert(s[i]-'a');

        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(i!=j && isPresent.find(i)!=isPresent.end() && isPresent.find(j)!=isPresent.end())
                {
                    for(int k=0;k<n;k++)
                    {
                        if((s[k]-'a')==i)
                            mark.push_back(1);
                        if((s[k]-'a')==j)
                            mark.push_back(-1);
                    }
                    int maxSum=maxSubArraySum(mark);
                    ans=max(maxSum,ans);
                }
                mark.clear();
            }
        }
        return ans;
    }
};
