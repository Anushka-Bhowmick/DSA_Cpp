class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        vector<double> maxProb(n,(double)INT_MIN);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        //<maxProb,node>
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        maxProb[start]=1.0;
        while(!pq.empty())
        {
            pair<double,int> cur=pq.top();
            int curNode=cur.second;
            double curNodeMaxProb=cur.first;
            pq.pop();
            for(auto x: adj[curNode])
            {
                int adjNode=x.first;
                int adjNodeProb=x.second;   
                if(maxProb[adjNode]<curNodeMaxProb*x.second)
                {
                    maxProb[adjNode]=curNodeMaxProb*x.second;
                    pq.push({maxProb[adjNode],adjNode});
                }
            }
        }
        return maxProb[end]==(double)INT_MIN?0.0:maxProb[end];
    }
};
