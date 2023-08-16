class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto data: nums) {
            freq[data]++;
        }

        vector<vector<int>> ans;
        bool allFreqZero=false;

        while(true) {
            vector<int> temp;
            int zeroFreqCount=0;
            for(auto it=freq.begin();it!=freq.end();it++) {
                if(it->second==0) {
                    zeroFreqCount++;
                } else {
                    temp.push_back(it->first);
                    it->second--;
                }
            }
            if(zeroFreqCount==freq.size())
                break;
            ans.push_back(temp);
        }

        return ans;
    }
};
