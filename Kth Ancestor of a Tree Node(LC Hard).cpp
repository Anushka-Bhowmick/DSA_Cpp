//Binary Lifting
class TreeAncestor {
public:
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int>& parent) {
        dp.assign(n,vector<int>(17,-1));
        for(int i=0;i<n;i++) {
            dp[i][0]=parent[i];
        }

        for(int j=1;j<=16;j++) {
            for(int i=1;i<n;i++) {
                if(dp[i][j-1]!=-1) {
                    dp[i][j]=dp[dp[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int cur=node;
        for(int i=15;i>=0;i--) {
            if(k&(1<<i)) {
                if(dp[cur][i]==-1)
                    return -1;
                cur=dp[cur][i];
            }
        }
        return cur;
    }
};
