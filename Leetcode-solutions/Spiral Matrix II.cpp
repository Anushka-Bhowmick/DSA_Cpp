typedef long long ll;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        ll num=1;
        vector<vector<int>> matrix(n,vector<int>(n));
        int rotate=0;

        ll a=0;
        ll b=0;
        ll c=n-1;
        ll d=n-1;

        while(b<=d && a<=c)
        {
            if(rotate==0)
            {
                for(int i=b;i<=d;i++)
                    matrix[a][i]=num++;
                a++;
            }
            else if(rotate==1)
            {
                for(int i=a;i<=c;i++)
                    matrix[i][d]=num++;
                d--;
            }
            else if(rotate==2)
            {
                for(int i=d;i>=b;i--)
                    matrix[c][i]=num++;
                c--;
            }
            else
            {
                for(int i=c;i>=a;i--)
                    matrix[i][b]=num++;
                b++;
            }
            rotate=(rotate+1)%4;
        }
        return matrix;
    }
};
