class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        unordered_map<int,int> freq;
        for(auto x: arr) {
            freq[x]++;
        }

        for(auto x: freq) {
            pq.push({x.second,x.first});
        }

        while(!pq.empty() && k) {
            int topEl=pq.top().second;
            int topElFreq=pq.top().first;
            topElFreq--;
            k--;
            pq.pop();
            if(topElFreq!=0) {
                pq.push({topElFreq,topEl});
            }
        }

        return pq.size();
    }
};
