#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define pb push_back
#define ff first
#define ss second
 
const ll llmx = (ll)9e18+7;
 
ll n, m;
ll g[510][510];
ll level[510], ptr[510];
vector<vector<ll>> v(510);
 
ll dfs(ll id, ll flow){
    if(id == n) return flow;
    for(; ptr[id] < (ll)v[id].size(); ptr[id]++){
        ll x = v[id][ptr[id]];
        if(g[id][x] > 0 && level[x] == level[id]+1){
            ll pushed = dfs(x, min(g[id][x], flow));
            if(pushed != 0){
                g[id][x] -= pushed;
                g[x][id] += pushed;
                return pushed;
            }
        }
    }
    return 0;
}
 
bool bfs(){
    queue<ll> q;
    q.push(1);
    for(ll i = 1; i <= n; i++) level[i] = 0;
    level[1] = 1;
    while(q.size()){
        ll id = q.front();
        q.pop();
        for(ll x: v[id]){
            if(g[id][x] > 0 && level[x] == 0){
                level[x] = level[id]+1;
                q.push(x);
            }
        }
    }
    if(level[n]) return 1;
    else return 0;
}
 
ll dinic(){
    ll f = 0;
    while(bfs()){
        for(ll i = 1; i <= n; i++) ptr[i] = 0;
        while(ll pushed = dfs(1, llmx)) f += pushed;
    }
    return f;
}
 
int main(){
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) g[i][j] = 0;
    for(ll i = 1; i <= m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        g[a][b] += c;
        v[a].pb(b), v[b].pb(a);
    }
    cout << dinic();
}