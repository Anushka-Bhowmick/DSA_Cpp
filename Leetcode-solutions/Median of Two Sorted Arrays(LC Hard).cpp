class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double answer=0.0;
        int n=nums1.size();
        int m=nums2.size();
        int total=n+m;
        bool totalEvenSize=((total%2)==0);
        int medianQuantity=total/2;

        //making nums1 smaller than nums2 to avoid overflow of index
        if(n>m) {
            return findMedianSortedArrays(nums2,nums1);
        }

        int low=0;
        int high=n;

        while(low<=high) {
            int cut1=low+(high-low)/2;
            int cut2=medianQuantity-cut1;

            int l1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int l2=(cut2==0)?INT_MIN:nums2[cut2-1];
            int r1=(cut1==n)?INT_MAX:nums1[cut1];
            int r2=(cut2==m)?INT_MAX:nums2[cut2];

            if(l1>r2) {
                high=cut1-1;
            } else if(l2>r1) {
                low=cut1+1;
            } else {
                if(totalEvenSize) {
                    answer=(double)((max(l1,l2)+min(r1,r2))/2.0);
                } else {
                    answer=(double)(min(r1,r2)*1.0);
                }
                break;
            }
        }
        return answer;
    }
};
