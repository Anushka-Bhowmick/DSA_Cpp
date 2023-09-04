#include <iostream>
using namespace std;
int hcf(int,int);
int main()
{
    int a,b,gcd;
    cout<< "Enter two numbers";
    cin>> a>>b;
    gcd = hcf(a,b);
    cout<< gcd;
}
int hcf(int p,int q)
{
    int r,f;
    r = p - (p/q*q);
    if(r ==0)
        return q;
    else
        hcf(q,r);
    return 0;    
}
