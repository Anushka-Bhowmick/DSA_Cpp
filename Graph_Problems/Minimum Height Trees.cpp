class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) { return {0}; }
        vector<int> ans;
        vector<int> deg(n,0);
        queue<int> q;
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
        }
        
        for(int i=0;i<n;i++) {
            if(deg[i]==1) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int m=q.size();
            ans.clear();
            for(int i=0;i<m;i++) {
                int cur=q.front();
                ans.push_back(cur);
                q.pop();
                deg[cur]--;
                for(auto adjNode: adj[cur]) {
                    deg[adjNode]--;
                    if(deg[adjNode]==1) {
                        q.push(adjNode);
                    }
                }
            }
        }
        return ans;
    }
};
