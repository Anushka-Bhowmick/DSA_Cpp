class Solution {
public:
    unsigned int helper(unsigned int up,unsigned int down)
    {
        if(down>up)
            return 0;
        long count=1;
        long temp=down;
        while(temp<=up)
        {
            count<<=1;
            temp<<=1;
        }
        count>>=1;
        temp>>=1;
        return count+helper(up-temp,down);
    }
    
    int divide(int dividend, int divisor) {
        if(dividend==-2147483648 && divisor==-1)
            return 2147483647;
        unsigned int up=dividend;
        unsigned int down=divisor;
        int sign=1;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
            sign=-1;
        if(dividend<0)
            up=-up;
        if(divisor<0)
            down=-down;
        return sign*helper(up,down);
    }
};
