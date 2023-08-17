class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU* dsu=new DSU(26);
        for(auto x: equations)
            if(x[1]=='=')
                dsu->Union(getInt(x[0]),getInt(x[3]));
        for(auto x: equations)
        {
            if(x[1]=='!')
            {
                if(dsu->find(getInt(x[0]))==dsu->find(getInt(x[3])))
                    return false;
            }
        }
        return true;
    }
    int getInt(char a) { return a-'a'; }
    
    class DSU {
    public:
        vector<int> parent;
        vector<int> rank;
        DSU(int v)
        {
            for(int i=0;i<=v;i++)
            {
                parent.push_back(i);
                rank.push_back(1);
            }
        }
        
        int find(int v)
        {
            if(v==parent[v])
                return v;
            int leader=find(parent[v]);
            parent[v]=leader;
            return leader;
        }
    
        void Union(int u, int v)
        {
            int lu=find(u);
            int lv=find(v);
            if(lu!=lv)
            {
                if(rank[lu]>rank[lv])
                    parent[lv]=lu;
                else if(rank[lu]<rank[lv])
                    parent[lu]=lv;
                else
                {
                    parent[lv]=lu;
                    rank[lu]++;
                }
            }
        }    
    };
};
