class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n==m) {
            bool isAnag=true;
            unordered_map<char,int> freq;
            for(int i=0;i<n;i++) {
                freq[s[i]]++;
                freq[t[i]]--;
            }
            for(auto it=freq.begin();it!=freq.end();it++) {
                if(it->second!=0) {
                    isAnag=false;
                    break;
                }
            }
            return isAnag;
        } else {
            return false;
        }
    }
};
