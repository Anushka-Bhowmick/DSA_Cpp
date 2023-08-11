#include<bits/stdc++.h>
using namespace std;
void print1(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int t;
    cout<<"enter t: ";
    cin>>t;
     int n;
    for(int i=0;i<t;i++){
        cout<<"Enter n: ";
        cin >> n;
        print1(n);
    }
    
}