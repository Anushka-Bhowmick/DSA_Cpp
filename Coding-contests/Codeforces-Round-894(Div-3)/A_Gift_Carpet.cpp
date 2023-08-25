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
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));

    for(int i=0;i<n;i++) {
        for (int j = 0; j < m; j++) {
            cin>>v[i][j];
        }
    }

    string s="vika";
    int k=0;

    for(int j=0;j<m;j++) {
        for(int i=0;i<n;i++) {
            if(v[i][j]==s[k]) {
                k++;
                break;
            }
        }
        if(k==4)
            return true;
    }

    return false;
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
