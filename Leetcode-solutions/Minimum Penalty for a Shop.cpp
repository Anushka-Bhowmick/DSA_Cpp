class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> suf(n+1,0);
        int minHour=0;
        int sum=0;

        for(int i=n-1;i>=0;i--) {
            suf[i]=suf[i+1]+(customers[i]=='Y');
        }
        int minPenalty=suf[0];

        for(int i=0;i<n;i++) {
            sum+=(customers[i]=='N');
            if(minPenalty>sum+suf[i+1]) {
                minPenalty=sum+suf[i+1];
                minHour=i+1;
            }
        }
        return minHour;
    }
};
