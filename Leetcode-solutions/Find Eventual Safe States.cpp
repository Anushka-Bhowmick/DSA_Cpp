class Solution {
public:
    bool detectAndMarkCycleNodes(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathVis) {
        vis[node]=true;
        pathVis[node]=true;
        for(auto adjNode: adj[node])
        {
            if(!vis[adjNode] && detectAndMarkCycleNodes(adjNode,adj,vis,pathVis))
                    return true;
            else if(pathVis[adjNode])
                return true;
        }
        pathVis[node]=false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        vector<bool> vis(n,false);
        vector<bool> pathVis(n,false);
        for(int i=0;i<n;i++)
            if(!vis[i])
                detectAndMarkCycleNodes(i,graph,vis,pathVis);

        for(int i=0;i<n;i++)
            if(!pathVis[i])
                ans.push_back(i);

        return ans;
    }
};
