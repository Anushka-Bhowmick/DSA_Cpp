class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat.at(0).size();
        int count=0;
        unordered_map<int,int> rOne;
        unordered_map<int,int> cOne;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]==1) {
                    rOne[i]++;
                    cOne[j]++;
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]==1 && rOne[i]==1 && cOne[j]==1) {
                    count++;
                }
            }
        }

        return count;
    }
};
