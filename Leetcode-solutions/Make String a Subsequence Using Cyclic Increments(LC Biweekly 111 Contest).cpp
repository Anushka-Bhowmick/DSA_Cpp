// O(n) two pointer
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        
        if(n<m)
            return false;

        int i=0;
        int j=0;
        
        while(i<n && j<m) {
            char shift=str1[i]+1>'z'?'a':str1[i]+1;
            if((shift==str2[j]) || (str1[i]==str2[j])) {
                j++;
            }
            i++;
        }
        
        return j==m;
    }
};
