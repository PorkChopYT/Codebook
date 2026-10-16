// check if the component is connected

struct DSU{
    ll n, m;
    vector<tuple<ll, ll, ll>> v;
    vector<vector<pair<ll, ll>>> graph;
    vector<ll> len, connected;

    DSU(ll N){
        n = N;
        graph.resize(n+5);
        len.resize(n+5, 1), connected.resize(n+5, 0);
        for(int i = 1; i <= n; i++) connected[i] = i;
    }

    void print(){
        for(int i = 1; i <= n; i++){
            cout << i << ": ";
            for(auto [x, w]: graph[i]) cout << x << ' ';
            cout << endl;
        }
    }

    void add_edge(ll a, ll b, ll c){
        graph[a].pb({b, c});
    }

    ll search(ll id){
        if(connected[id] == id) return id;
        return connected[id] = search(connected[id]);
    }

    void unite(ll a, ll b){
        a = search(a);
        b = search(b);
        if(a == b) return;
        if(len[a] < len[b]) swap(a, b);
        len[a] += len[b];
        connected[b] = a;
    }

    ll kruskal(){
        for(int i = 0; i <= n; i++)
            for(auto [x, w]: graph[i])
                v.pb({w, i, x});
        sort(v.begin(), v.end(), cmp);
        ll w = 0;
        for(auto [c, a, b]: v){
            if(search(a) != search(b)){
                unite(a, b); // use vector.push_back({a, b, w}); to store answer
                w += c;
            }
        }
        return w;        
    }
};
