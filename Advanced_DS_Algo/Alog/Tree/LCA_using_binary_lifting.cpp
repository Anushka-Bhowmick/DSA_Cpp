#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll jump(vector<vector<ll>>& dp, ll node, ll k) {
    ll cur=node;
    for(ll i=18;i>=0;i--) {
        if((1<<i)&k) {
            if(dp[cur][i]==-1) {
                return -1;
            }
            cur=dp[cur][i];
        }
    } 
    return cur;
}

ll lca(ll u,ll v, vector<vector<ll>>& dp, vector<ll>& level) {
    if(level[u]>level[v]) {
        return lca(v,u,dp,level);
    }
    v=jump(dp,v,level[v]-level[u]);
    if(u==v) {
        return v;
    } else {
        for(ll i=18;i>=0;i--) {
            if(dp[u][i]!=dp[v][i]) {
                u=dp[u][i];
                v=dp[v][i];
            }
        }
    }
    return dp[u][0];
}

int main() {
    /*
    LCA of two nodes using Binary Lifting:-
    -----------------------------------------------------------------------------------------
    Time complexity:- O(n)+O(nlog(k))+O(n)+O(qlog(k)) wich id overall O(max(n,q)log(k))
    Space complexity:- O(nlog(k))
    Tree root node rooted at 1, nodes are numbered from [1....n].
    q queries to find LCA, tree input will be givenm where parent[i] will be the parent of i.
    */
    ll n,q;
    cin>>n>>q;
    vector<vector<ll>> adj(n+1);
    vector<ll> level(n+1,0);
    vector<bool> vis(n+1,false);
    vector<vector<ll>> dp(n+1,vector<ll>(19,-1));
    //Pre computation
    dp[1][0]=-1;
    for(ll i=2;i<=n;i++) {
        ll x;
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
        dp[i][0]=x;
    }

    for(ll i=2;i<=n;i++) {
        for(ll j=1;j<=18;j++) {
            if(dp[i][j-1]!=-1) {
                dp[i][j]=dp[dp[i][j-1]][j-1];
            }
        }
    }

    queue<pair<ll,ll>> qu;
    qu.push({1,0});
    vis[1]=true;

    while(!qu.empty()) {
        pair<ll,ll> cur=qu.front();
        level[cur.first]=cur.second;
        vis[cur.first]=true;
        qu.pop();
        for(auto x: adj[cur.first]) {
            if(!vis[x]) {
                qu.push({x,cur.second+1});
            }
        }
    }    

    while(q--) {
        ll node1,node2;
        cin>>node1>>node2;
        cout<<lca(node1,node2,dp,level)<<endl;
    }

    return 0;
}
