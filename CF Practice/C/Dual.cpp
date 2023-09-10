#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vector<ll>> vvll;
typedef map<ll,bool> mllb;
typedef unordered_set<char> ucst;
typedef unordered_map<ll,bool> umllb;
#define PI 3.1415926535897932384626
#define pb push_back
#define mp make_pair
const ll mod=10e9+7;

void solve() {
    ll n;
    vpll ans;
    cin>>n;
    vll arr(n);
    ll pos=0,neg=0,zero=0;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]>0) {
            pos++;
        } else if(arr[i]<0) {
            neg++;
        } else {
            zero++;
        }
    }

    if(zero==n) {
        cout<<0<<endl;
    } else {
        if(pos+zero==n || pos==n) {
            cout<<n-1<<endl;
            for(ll i=2;i<=n;i++) {
                ans.push_back({i,i-1});
            }
        } else if(neg+zero==n || neg==n) {
            cout<<n-1<<endl;
            for(ll i=n;i>=2;i--) {
                ans.push_back({i-1,i});
            }
        } else if(neg+pos+zero==n) {
            ll count=0;
            ll mx=-21;
            ll mxi=-1;
            for(ll i=0;i<n;i++) {
                if(arr[i]!=0 && arr[i]>mx) {
                    mx=arr[i];
                    mxi=i;
                }
            }

            while(mx<=20) {
                ans.push_back({mxi+1,mxi+1});
                count++;
                mx*=2;
            }

            for(ll i=0;i<n;i++) {
                if(i!=mxi) {
                    ans.push_back({i+1,mxi+1});
                    count++;
                }
            }

            for(ll i=2;i<=n;i++) {
                ans.push_back({i,i-1});
                count++;
            }
            cout<<count<<endl;
        }
    }

    for(auto x: ans) {
        cout<<x.first<<" "<<x.second<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    //t=1;
    while(t--) {
        /*if(solve())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;*/
        solve();
        //cout<<solve()<<endl;
    }

    return 0;
}
