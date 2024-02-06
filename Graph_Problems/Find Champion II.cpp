class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int e=edges.size();
        vector<int> indeg(n,0);
        for(int i=0;i<e;i++) {
            indeg[edges[i][1]]++;
        }
        int count=0;
        int ans=-1;
        for(int i=0;i<n;i++) {
            if(indeg[i]==0) {
                count++;
                ans=i;
            }
        }
        return count==1?ans:-1;
    }
};
