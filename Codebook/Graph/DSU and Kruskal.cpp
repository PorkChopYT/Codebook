// check if the component is connected

struct DSU{
    ll n, m;
    vector<tll> edge;
    vector<ll> sz, connected;

    DSU(ll N){
        n = N;
        graph.resize(n+5);
        sz.resize(n+5, 1), connected.resize(n+5, 0);
        for(int i = 1; i <= n; i++) connected[i] = i;
    }

    ll search(ll id){
        if(connected[id] == id) return id;
        return connected[id] = search(connected[id]);
    }

    void unite(ll a, ll b){
        a = search(a);
        b = search(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        connected[b] = a;
    }

    ll kruskal(){
        for(int i = 0; i <= n; i++)
            for(auto [x, w]: graph[i])
                edge.pb({w, i, x});
        sort(edge.begin(), edge.end());
        ll ans = 0;
        for(auto [w, a, b]: edge){
            if(search(a) != search(b)){
                unite(a, b); // use vector.push_back({a, b, w}); to store answer
                ans += w;
            }
        }
        return w;        
    }
};
