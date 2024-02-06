class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int count=0;
        unordered_set<string> dead;
        unordered_set<string> vis;
        for(auto d: deadends) {
            dead.insert(d);
        }
        queue<string> qu;
        qu.push("0000");
        vis.insert("0000");
        while(!qu.empty()) {
            int n=qu.size();
            for(int i=0;i<n;i++) {
                string curState=qu.front();
                if(curState==target)
                    return count;
                qu.pop();
                vector<string> nstates=nextStates(curState);
                for(int i=0;i<nstates.size();i++) {
                    if(dead.find(curState)==dead.end() && !visited(vis,nstates[i])) {
                        qu.push(nstates[i]);
                        vis.insert(nstates[i]);
                    }
                }
            }
            count++;
        }
        return -1;
    }
    
    bool visited(unordered_set<string>& vis, string st) {
        return vis.find(st)!=vis.end();
    }
    
    vector<string> nextStates(string curState) {
        vector<string> states;
        for(int i=0;i<4;i++)
        {
            string next=curState;
            string prev=curState;
            next[i]=(((next[i]-'0')+1)%10)+'0';
            prev[i]=='0'?prev[i]='9':prev[i]=((prev[i]-'0')-1)+'0';
            states.push_back(next);
            states.push_back(prev);
        }
        return states;
    }
};
