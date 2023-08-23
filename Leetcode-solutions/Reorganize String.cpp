/*
Contributed by Supratim Bhattacharjee

Reorganize String(LC Medium)
String and Hashing with pigeonhole principle
Time complexity:- 26*O(n) -> nearly O(n)
Space Complexity:- O(26) -> Considerd as constant extra space
*/

class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        string ans="";
        vector<int> freq(26,0);
        int maxFreq=0;
        char maxFreqChar;

        for(int i=0;i<n;i++) {
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']>maxFreq) {
                maxFreq=freq[s[i]-'a'];
                maxFreqChar=s[i];
            }
        }

        if(maxFreq<=(n+1)/2) {
            for(int i=0;i<n;i++) {
                ans.push_back('x');
            }
            
            int i=0;

            while(freq[maxFreqChar-'a']!=0) {
                ans[i]=maxFreqChar;
                freq[maxFreqChar-'a']--;
                i+=2;
            }

            for(int j=0;j<26;j++) {
                while(freq[j]>0) {
                    if(i==s.size() || i==s.size()+1) {
                        i=1;
                    }
                    ans[i]=(char)(j+'a');
                    freq[j]--;
                    i+=2;
                }
            }
        }

        return ans; 
    }
};
