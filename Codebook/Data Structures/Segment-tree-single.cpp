// be aware that range queries might cause overflow
// 1-indexed
struct segment_tree{
    ll n;
    vector<ll> tree;
 
    segment_tree(ll N, ll arr[]){
        n = N;
        tree.resize(4*n+10, 0);
        build(1, 1, n, arr);
    }
    
    void print(){ // debug
        for(ll x: tree) cout << x << ' ';
        cout << endl;
    }
 
    void build(ll id, ll l , ll r, ll arr[]) {
        if(l == r){
            tree[id] = arr[l];
            return;
        }
        ll mid = (l+r)/2;
        build(2*id, l, mid, arr);
        build(2*id+1, mid+1, r, arr);
        tree[id] = tree[2*id]+tree[2*id+1]; // for different queries change this line
    }
 
    ll query(ll id, ll l, ll r, ll ql, ll qr){
        if(ql <= l && qr >= r) return tree[id];
        ll mid = (l+r)/2, total = 0; // total = 0 -> total = llmx for minimum range query
        if(ql <= mid) total += query(2*id, l, mid, ql, qr);
        if(qr > mid) total += query(2*id+1, mid+1, r, ql, qr);
        // for different queries change this line
        return total;
    }
 
    void modify(ll id, ll l, ll r, ll pos, ll x){
        if(l == r){
            tree[id] = x;
            return;
        }
        ll mid = (l+r)/2;
        if(l <= pos && pos <= mid) modify(2*id, l, mid, pos, x);
        else modify(2*id+1, mid+1, r, pos, x);
        tree[id] = tree[2*id]+tree[2*id+1]; // for different queries change this line
    }
};
