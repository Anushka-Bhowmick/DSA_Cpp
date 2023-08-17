class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxProd;
        int maxProdSuf=INT_MIN;
        int maxProdPre=INT_MIN;
        int maxNum=INT_MIN;
        int prodPre=1;
        int prodSuf=1;
        for(int i=0;i<n;i++)
        {
            maxNum=max(maxNum,nums[i]);
            if(nums[i]==0 && nums[n-i-1]==0)
            {
                prodPre=1;
                prodSuf=1;
            }
            else if(nums[i]==0)
            {
                prodPre=1;
                prodSuf=prodSuf*nums[n-i-1];
                maxProdSuf=max(maxProdSuf,prodSuf);
                
            }
            else if(nums[n-i-1]==0)
            {
                prodSuf=1;
                prodPre=prodPre*nums[i];
                maxProdPre=max(maxProdPre,prodPre);
            }
            else
            {
                prodPre=prodPre*nums[i];
                prodSuf=prodSuf*nums[n-i-1];
                maxProdPre=max(maxProdPre,max(prodSuf,prodPre));
                maxProdSuf=max(maxProdSuf,max(prodSuf,prodPre));
            }
        }
        maxProd=max(maxNum,max(maxProdSuf,maxProdPre));
        return maxProd;
    }
};
