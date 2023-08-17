class Solution {
public:
    void generate(int initVal, int k, int n, vector<int>& temp, vector<vector<int>>& ans) {
        if(k==0) {
            ans.push_back(temp);
            return;
        }
        
        for(int x=initVal;x<=n;x++) {
            temp.push_back(x);
            generate(x+1,k-1,n,temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        generate(1,k,n,temp,ans);
        return ans;
    }
};
