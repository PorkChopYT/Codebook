// 1-indexed
struct sparse_table{
    vector<array<ll, 20>> st; // 30 for 10^9, 60 for long long
    ll n;

    sparse_table(ll sz, ll arr[]){ // 2 input for initialize
        n = sz;
        st.resize(n+1);

        for(ll i = 1; i <= n; i++) st[i][0] = arr[i];
        for(ll k = 1; (1LL << k) <= n; k++){
            for(ll i = 1; i <= n; i++){
                if(i+(1LL << (k-1)) > n) st[i][k] = st[i][k-1];
                else st[i][k] = min(st[i][k-1],
                                    st[i+(1LL << (k-1))][k-1]); 
                // for different queries change this line
            }
        }
    }

    ll query(ll l, ll r){
        ll id = __lg(r-l+1);
        return min(st[l][id], st[r-(1LL << id)+1][id]);
        // for different queries change this line
    }
};
