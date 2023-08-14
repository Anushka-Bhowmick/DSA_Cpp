class Solution {
public:
    
    int num(char ch)
    {
        return ch-48;
    }
    
    void reverseString(string& str)
    {
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }
    
    string addBinary(string a, string b) {
        string ans="";
        int sum=0,carry=0;
        int i=a.size()-1;
        int j=b.size()-1;
        while(i>=0 && j>=0)
        {
            sum=num(a[i])^num(b[j])^carry;
            carry=num(a[i])&num(b[j]) | num(b[j])&carry | num(a[i])&carry;
            ans+=((char)(sum+48));
            i--;
            j--;
        }
        if(i==-1)
        {
            while(j>=0)
            {
                sum=num(b[j])^carry;
                carry=num(b[j])&carry;
                ans+=((char)(sum+48));
                j--;
            }
        }
        else
        {
            while(i>=0)
            {
                sum=num(a[i])^carry;
                carry=num(a[i])&carry;
                ans+=((char)(sum+48));
                i--;
            }
        }
        
        if(carry!=0)
            ans+='1';
        
        reverseString(ans);
        
        return ans;
    }
};
