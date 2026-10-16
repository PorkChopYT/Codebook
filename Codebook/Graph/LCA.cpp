struct LCA{
    vector<array<ll, 20>> jump;
    vector<ll> par, depth;
    ll n = 0;
    
    LCA(ll sz){
        n = sz;
        jump.resize(sz+10);
        par.resize(sz+10, 0);
        depth.resize(sz+10, 0);
        bfs();
        binary_lifting();
    }
    
    void bfs(){ // Assume the root is 1
        queue<pair<ll, ll>> q;
        q.push({1, 1});
        par[1] = 1, depth[1] = 0;
        while(q.size()){
            ll id = q.front().ff, p = q.front().ss;
            q.pop();
            par[id] = p;
            for(ll x: v[id]){
                if(par[x] == 0){
                    par[x] = id;
                    depth[x] = depth[id]+1;
                    q.push({x, id});
                }
            } 
        }
    }
    
    void binary_lifting(){
        for(ll i = 1; i <= n; i++) jump[i][0] = par[i];
        for(ll j = 1; (1LL << j) <= n; j++)
            for(ll i = 1; i <= n; i++)
                jump[i][j] = jump[jump[i][j-1]][j-1];
    }
    
    ll move(ll x, ll k){
        for(ll i = 0; i <= __lg(n); i++)
            if(k & (1LL << i)) x = jump[x][i];
        return x;
    }
    
    ll lca(ll a, ll b){
        if(depth[a] > depth[b]) a = move(a, depth[a]-depth[b]);
        else if(depth[b] > depth[a]) b = move(b, depth[b]-depth[a]);
        if(a == b) return a;
        for(ll i = __lg(n); i >= 0; i--){
            if(jump[a][i] != jump[b][i]){
                a = jump[a][i];
                b = jump[b][i];
            }
        }
        return jump[a][0];
    }
};