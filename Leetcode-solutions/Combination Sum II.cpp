class Solution {
public:
        void generateSubsets(vector<int>& candidates, vector<vector<int>>& ans, vector<int> curState, int i, int target) {
        if(target<0)
            return;
        if(target==0)
        {
            ans.push_back(curState);
            return;
        }
        if(i==candidates.size())
            return;
        curState.push_back(candidates[i]);
        generateSubsets(candidates, ans, curState, i+1, target-candidates[i]);
        curState.pop_back();
        int cur=candidates[i];
        int newIndex=i;
        while(newIndex<candidates.size() && candidates[i]==candidates[newIndex])
            newIndex++;
        if(newIndex<candidates.size())
            generateSubsets(candidates, ans, curState, newIndex, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curState;
        sort(candidates.begin(),candidates.end());
        generateSubsets(candidates, ans, curState, 0, target);
        return ans;
    }
};
