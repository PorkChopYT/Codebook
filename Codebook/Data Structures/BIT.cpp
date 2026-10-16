// 1-indexed

struct BIT{
    ll n;
    vector<ll> tree;

    BIT(ll N, ll arr[]){
        n = N;
        tree.resize(n+10, 0);
        build(arr);
    }
    
    void print(){ // debug
        for(ll x: tree) cout << x << ' ';
        cout << endl;
    }

    void build(ll arr[]) {
        for (int i = 1; i <= n; i++) {
            tree[i] += arr[i];
            int j = i+(i&(-i));
            if(j <= n) tree[j] += tree[i];
        }
    }

    ll sum(ll id){
        ll ans = 0;
        while(id) ans += tree[id], id -= (id&(-id));
        return ans;
    }

    void modify(ll id, ll x){
        while(id <= n) tree[id] += x, id += (id&(-id));
    }
};
