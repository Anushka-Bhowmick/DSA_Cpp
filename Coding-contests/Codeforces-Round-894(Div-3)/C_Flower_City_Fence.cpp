#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vector<ll>> vvll;
typedef map<ll, bool> mllb;
typedef unordered_set<char> ucst;
typedef unordered_map<ll, bool> umllb;
#define PI 3.1415926535897932384626
#define pb push_back
#define mp make_pair
const ll mod = 10e9 + 7;

bool solve()
{
    ll n;
    cin>>n;
    vll arr(n);
    vll hash(n,0);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
 
    for(ll i=0;i<n;i++) {
        if(arr[i]-1>=n) {
            return false;
        }
        hash[arr[i]-1]++;
    }
 
    for(ll i=n-2;i>=0;i--) {
        hash[i]=hash[i]+hash[i+1];
    }
 
    bool posible=true;
 
    for(ll i=0;i<n;i++) {
        if(arr[i]!=hash[i]) {
            posible=false;
            break;
        }
    }
 
    return posible;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    // t=1;
    while (t--)
    {
        if(solve())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        //solve();
        // cout<<solve()<<endl;
    }

    return 0;
}
