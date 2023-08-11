#include<bits/stdc++.h>
using namespace std;
void print2(int n){
    for(int i=0;i<n;i++){
       //spaces
       for(int j=0;j<n-i-1;j++){
           cout<<" ";
       }
       //stars
       for(int j=0;j<2*i+1;j++){
           cout<<"*";
       }
       //spaces
       for(int j=0;j<n-i-1;j++){
           cout<<" ";
       }
        cout<<endl;
    }
}
void print1(int n){
    for(int i=0;i<n;i++){
       //spaces
       for(int j=0;j<i;j++){
           cout<<" ";
       }
       //stars
       for(int j=0;j<2*(n-i-1)+1;j++){
           cout<<"*";
       }
       //spaces
       for(int j=0;j<i;j++){
           cout<<" ";
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
        print2(n);
        print1(n);
    }
    
}