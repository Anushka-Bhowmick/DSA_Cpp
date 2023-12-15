class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid.at(0).size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        unordered_map<int,int> rMap;
        unordered_map<int,int> cMap;
        for(int i=0;i<n;i++) {
            int o=0;
            int z=0;
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) {
                    o++;
                } else {
                    z++;
                }
            }
            rMap[i]=o-z;
        }
        
        for(int j=0;j<m;j++) {
            int o=0;
            int z=0;
            for(int i=0;i<n;i++) {
                if(grid[i][j]==1) {
                    o++;
                } else {
                    z++;
                }
            }
            cMap[j]=o-z;
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans[i][j]=rMap[i]+cMap[j];
            }
        }
        
        return ans;
    }
};
