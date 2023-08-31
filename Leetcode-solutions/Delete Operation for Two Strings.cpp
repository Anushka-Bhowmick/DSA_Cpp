class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int> prv(m+1,0);
        vector<int> cur(m+1,0);

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(text1[i-1]==text2[j-1]) {
                    cur[j]=1+prv[j-1];
                } else {
                    cur[j]=max(prv[j],cur[j-1]);
                }
            }
            prv=cur;
        }
        return prv[m];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int  lcs=longestCommonSubsequence(word1,word2);
        return n+m-2*lcs;
    }
};
