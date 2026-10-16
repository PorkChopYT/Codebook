vector<vector<pair<ll, ll>>> v(2010);
ll dis[2010];

bool Bellman_Ford(){ // return true if no negative cycle
    for(ll i = 1; i <= n; i++) dis[i] = llmx;
    for(ll iter = 0; iter < n; iter++){
        bool relax = 0;
        for(ll i = 1; i <= n; i++){
            for(auto [a, b]: v[i]){
                if(dis[a] > dis[i]+b){
                    dis[a] = dis[i]+b;
                    relax = 1;
                }
            }
        }
        if(!relax) return true;
    }
    return false;
}