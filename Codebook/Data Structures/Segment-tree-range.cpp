// be aware that range queries might cause overflow
// 1-indexed
struct node{
    ll mul, add; // change this for different lazy type
};

struct segment_tree{
    ll n;
    vector<ll> tree;
    vector<node> lazy;
 
    segment_tree(ll N, ll arr[]){
        n = N;
        tree.resize(4*n+10, 0);
        lazy.resize(4*n+10, {1, 0}); // change the initialization for different lazy type
        build(1, 1, n, arr);
    }
    
    void apply(ll id, ll len, ll mul, ll add){ // range multiplication and range addition
         // change this for different lazy type, %mod if needed
        tree[id] = (tree[id]*mul+add*len); 
        lazy[id].mul = (lazy[id].mul*mul);
        lazy[id].add = (lazy[id].add*mul+add);
    }
    
    void push(ll id, ll l, ll r){
        if(lazy[id].mul == 1 && lazy[id].add == 0) return; // change this for different lazy type
        ll mid = (l+r)/2;
        // change the following 3 lines for different lazy type
        apply(2*id, mid-l+1, lazy[id].mul, lazy[id].add); // input
        apply(2*id+1, r-mid, lazy[id].mul, lazy[id].add); // input
        lazy[id].mul = 1, lazy[id].add = 0; // initialize
    }
 
    void build(ll id, ll l, ll r, ll arr[]){
        if(l == r){
            tree[id] = arr[l];
            return;
        }
        ll mid = (l+r)/2;
        build(2*id, l, mid, arr);
        build(2*id+1, mid+1, r, arr);
        tree[id] = (tree[2*id]+tree[2*id+1])%mod; // change this for different query
    }
    
    ll query(ll id, ll l, ll r, ll ql, ll qr){
        if(ql <= l && qr >= r) return tree[id];
        push(id, l, r);
        ll mid = (l+r)/2, total = 0; // total = 0 -> total = llmx for minimum range query
        if(ql <= mid) total += query(2*id, l, mid, ql, qr);
        if(qr > mid) total += query(2*id+1, mid+1, r, ql, qr);
        // change these two lines for different query
        return total; // %mod if needed
    }
 
    void modify(ll id, ll l, ll r, ll ql, ll qr, ll mul, ll add){ // change the input for different lazy type
        if(ql <= l && qr >= r){
            apply(id, r-l+1, mul, add); // change the input for different type of lazy
            return;
        }
        push(id, l, r);
        ll mid = (l+r)/2;
        if(ql <= mid) modify(2*id, l, mid, ql, qr, mul, add);
        if(qr > mid) modify(2*id+1, mid+1, r, ql, qr, mul, add);
        tree[id] = tree[2*id]+tree[2*id+1]; // change this for different query
    }
};
