class Solution {
public:
    int minDeletions(string s) {
        int n=s.length();
        int ans=0;
        unordered_map<char,int> freq;
        map<int,int> freqfreq;
        for(int i=0;i<n;i++) {
            freq[s[i]]++;
        }

        for(auto x: freq) {
            freqfreq[x.second]++;
        }

        int mx=(freqfreq.rbegin()->first);
        stack<int> st;
        for(int i=1;i<=mx;i++) {
            if(freqfreq.find(i)==freqfreq.end()) {
                st.push(i);
            }
        }

        for(auto it=freqfreq.rbegin();it!=freqfreq.rend();it++) {
            while(it->second!=1) {
                if(st.empty()) {
                    ans+=(it->first);
                    (it->second)--;
                } else {
                    while(!st.empty() && st.top()>=(it->first)) {
                        st.pop();
                    }
                    if(!st.empty()) {
                        ans+=(it->first)-st.top();
                        (it->second)--;
                        st.pop();
                    }
                }
            }
        }

        return ans;
    }
};
