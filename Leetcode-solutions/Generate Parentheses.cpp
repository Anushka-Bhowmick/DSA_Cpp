class Solution {
public:
    void help(string str,int op,int cl,vector<string>& ans)
    {
        if(cl<op)
            return;
        if(op==0 && cl==0)
            ans.push_back(str);
        else if(op==0)
            help(str+")",op,cl-1,ans);
        else
        {
            help(str+"(",op-1,cl,ans);
            help(str+")",op,cl-1,ans);    
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        help("",n,n,ans);
        return ans;
    }
};
