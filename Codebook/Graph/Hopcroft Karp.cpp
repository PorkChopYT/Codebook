ll n, m, k; // n: left node, m: right node
vector<vector<ll>> v(510); // v[i][j] means node i on the left connects to node j on the right
ll matchL[510], matchR[510], level[1010]; // check matchL != llmx to see if there is a match
 
bool bfs(){
    queue<ll> q;
    for(ll i = 1; i <= n; i++) level[i] = llmx;
    for(ll i = 1; i <= n; i++) if(!matchL[i]) level[i] = 1, q.push(i);
    level[0] = llmx;
    while(q.size()){
        ll id = q.front();
        q.pop();
        if(level[id] >= level[0]) continue;
        for(ll x: v[id]){
            ll nxt = matchR[x];
            if(level[nxt] == llmx){
                level[nxt] = level[id]+1;
                if(nxt != 0) q.push(nxt);
            }
        }
    }
    return (level[0] != llmx);
}
 
bool dfs(ll id){
    if(id == 0) return 1;
    bool is_matched = 0;
    for(ll x: v[id]){
        ll nxt = matchR[x];
        if(level[nxt] == level[id]+1) is_matched = dfs(nxt);
        else continue;
        if(is_matched){ 
            matchR[x] = id;
            matchL[id] = x;
            return 1;
        }
    }
    level[id] = llmx;
    return 0;
}
 
ll hopcroft_karp(){
    for(ll i = 1; i <= n; i++) matchL[i] = 0;
    for(ll i = 1; i <= m; i++) matchR[i] = 0;
    ll ans = 0;
    while(bfs())
        for(ll i = 1; i <= n; i++) if(!matchL[i] && dfs(i)) ans++;
    return ans;
}
