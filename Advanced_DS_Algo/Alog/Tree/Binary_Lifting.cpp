#include<bits/stdc++.h>
using namespace std;

class BinaryLifting {
private:
    vector<vector<int>> dp;
public:
    BinaryLifting(int n, vector<int>& parent) {
        dp.assign(n,vector<int>(27,-1));
        for(int i=0;i<n;i++) {
            dp[i][0]=parent[i];
        }

        for(int j=1;j<=26;j++) {
            for(int i=1;i<n;i++) {
                if(dp[i][j-1]!=-1) {
                    dp[i][j]=dp[dp[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int cur=node;
        for(int i=25;i>=0;i--) {
            if(k&(1<<i)) {
                if(dp[cur][i]==-1)
                    return -1;
                cur=dp[cur][i];
            }
        }
        return cur;
    }
};


int main() {
    int n,query;
    cin>>n>>query;

    // i is the parent of parent[i] in tree;
    // Tree is zero rooted so parent[0]=-1;
    vector<int> parent(n);

    for(int& x: parent) {
        cin>>x;
    }

    BinaryLifting* obj = new BinaryLifting(n, parent);
    while(query--) {
        int node,k;
        cin>>node>>k;
        cout<<obj->getKthAncestor(node,k)<<endl;
    }

    return 0;
}
