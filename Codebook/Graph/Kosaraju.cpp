ll n, m, cnt;
vector<vector<ll>> graph(100010);
vector<vector<ll>> rev_graph(100010);
ll scc[100010];
vector<ll> s;
bool isvisited[100010];

void dfs1(ll id) {
    isvisited[id] = 1;
    for(ll x: graph[id]) if (!isvisited[x]) dfs1(x);
    s.pb(id);
}

void dfs2(ll id) {
    isvisited[id] = 1;
    scc[id] = cnt;
    for(ll x: rev_graph[id]) if(!isvisited[x]) dfs2(x);
}

void kosaraju() {
    s.clear();
    cnt = 1;
    for(ll i = 1; i <= n; i++) isvisited[i] = 0;
    for(ll i = 1; i <= n; i++) if(!isvisited[i]) dfs1(i);
    for(ll i = 1; i <= n; i++) isvisited[i] = 0;
    for(ll i = (ll)s.size() - 1; i >= 0; i--) {
        if(!isvisited[s[i]]) {
            dfs2(s[i]);
            cnt++;
        }
    }
    cnt--; // scc count
}