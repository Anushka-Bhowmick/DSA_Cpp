//Space optimised Dynamic Programming
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> prev(n+1,-1);
        vector<int> cur(m+1,-1);

        for(int i=0;i<=m;i++) {
            prev[i]=i;
        }

        for(int i=1;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(j==0) {
                    cur[j]=i;
                } else {
                    if(word1[i-1]==word2[j-1]) {
                        cur[j]=prev[j-1];
                    } else {
                        cur[j]=1+min(prev[j-1],min(cur[j-1],prev[j]));
                    }
                }
            }
            prev=cur;
        }
        
        return prev[m];
    }
};
