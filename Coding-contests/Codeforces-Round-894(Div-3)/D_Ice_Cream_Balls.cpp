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

ll solve()
{
    ll n;
    cin>>n;

    if(n==2) {
        return 3;
    }
    if(n==1) {
        return 2;
    }

    ll low=1;
    ll high=10000000000;
    ll ans=LLONG_MIN;
    ll temp=LLONG_MAX;

    while(low<=high) {
        ll mid=low+(high-low)/2;

        if(mid*(mid-1)/2<=n) {
            ans=mid*(mid-1)/2;
            temp=mid;
            low=mid+1;
        } else {
            high=mid-1;
        }
    }

    return n-ans+temp;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    // t=1;
    while (t--)
    {
        /*if(solve())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;*/
        cout<<solve()<<endl;
        // cout<<solve()<<endl;
    }

    return 0;
}
