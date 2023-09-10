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
const ll mod=1e9+7;
#define INT_SIZE 32
 
class TrieNode {
public:
    TrieNode* zero;
    TrieNode* one;
    TrieNode(TrieNode* zero=nullptr,TrieNode* one=nullptr) {
        this->zero=nullptr;
        this->one=nullptr;
    }
};
 
void buildTrie(TrieNode *root, int num) {
    TrieNode *cur = root;
    for (int i = 31; i >= 0; i--) {
        int curBit = num & (1 << i);
        if (curBit == 0) {
            if (cur->zero == nullptr) {
                cur->zero = new TrieNode();
            }
            cur = cur->zero;
        }
        else {
            if (cur->one == nullptr) {
                cur->one = new TrieNode();
            }
            cur = cur->one;
        }
    }
}
 
int findMaxXorForCurrentElement(TrieNode *root, int num) {
    TrieNode *cur = root;
    int maxXorCurElement = 0;
    for (int i = 31; i >= 0; i--) {
        int curBit = num & (1 << i);
        if (curBit == 0) {
            if (cur->one != nullptr) {
                maxXorCurElement |= 1 << i;
                cur = cur->one;
            }
            else {
                cur = cur->zero;
            }
        }
        else {
            if (cur->zero != nullptr) {
                maxXorCurElement |= 1 << i;
                cur = cur->zero;
            }
            else {
                cur = cur->one;
            }
        }
    }
    return maxXorCurElement;
}
 
int findMaximumXOR(vector<int> &nums) {
    int n = nums.size();
    int maxXor = 0;
    TrieNode *root = new TrieNode();
 
    for (int i = 0; i < n; i++) {
        buildTrie(root, nums[i]);
    }
 
    for (int i = 0; i < n; i++) {
        maxXor = max(findMaxXorForCurrentElement(root, nums[i]), maxXor);
    }
 
    return maxXor;
}
 
int maxSubarrayXOR(int N, vector<int> arr)
{
    vector<int> preXor(N + 1);
    preXor[0] = 0;
    for (int i = 1; i <= N; i++) {
        preXor[i] = preXor[i - 1] ^ arr[i - 1];
    }
    return findMaximumXOR(preXor);
}
 
void solve() {
    ll n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
 
    cout<<maxSubarrayXOR(n,arr)<<endl;
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
