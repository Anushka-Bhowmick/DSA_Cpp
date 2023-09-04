#include <iostream>
using namespace std;
long int fact(int);
int main() {
    int n;
    cout<< "Enter a number";
    cin>> n;
    cout<< "Factorial is "<< fact(n);
    return 0;
}
long int fact(int n)
{
    if(n == 0)
        return (1);
    else
        return(n*fact(n-1));
}
