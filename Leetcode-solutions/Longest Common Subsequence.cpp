/*
Contributed by Supratim Bhattacharjee

Longest Common Subsequence(LC Medium)
Dynamic Programming(Space Optimized)
Time complexity:- O(m*n)
Space Complexity:- O(m)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();

        /*
            Shifting Index
            0 means -1
            n/m means n-1/m-1
        */ 
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
};
