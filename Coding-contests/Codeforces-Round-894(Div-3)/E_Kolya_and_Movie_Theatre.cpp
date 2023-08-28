#include <bits/stdc++.h>
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
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll n,m,d;
    cin>>n>>m>>d;
    vll arr(n);
    for(ll& inp: arr) {
        cin>>inp;
    }

    ll sum=0;
    ll ans=0;

    for(int i=0;i<n;i++) {
        if(arr[i]>0) {
            sum+=arr[i];
        }
        if(pq.size()>m-1) {
            sum-=pq.top();
            pq.pop();
        }
        if(arr[i]>0) {
            pq.push(arr[i]);
        }
        ans=max(sum-(d*(i+1)),ans);
    }

    return ans;
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
        //solve();
        cout<<solve()<<endl;
    }

    return 0;
}
