// Assume that w1 = h2

vector<vector<ll>> mat_mul(const vector<vector<ll>> m1, const vector<vector<ll>> m2){
    ll h1 = m1.size(), h2 = m2.size(), w1 = m1[0].size(), w2 = m2[0].size();
    vector<vector<ll>> m3(h1);
    for(ll i = 0; i < h1; i++) for(ll j = 0; j < w2; j++) m3[i].pb(0);
    for(ll i = 0; i < h1; i++)
        for(ll j = 0; j < w2; j++)
            for(ll k = 0; k < w1; k++)
                m3[i][j] = ((__int128)m3[i][j] + m1[i][k]*m2[k][j])%mod;
    return m3;
}


vector<vector<ll>> mat_pow(const vector<vector<ll>> mat, ll p){
    ll sz = mat.size();
    vector<vector<ll>> re(sz), temp = mat;
    for(ll i = 0; i < sz;i++){
        for(ll j = 0; j < sz; j++){
            if(i == j) re[i].pb(1);
            else re[i].pb(0);
        }
    }
    while(p > 0){
        if(p & 1) re = mat_mul(re, temp);
        temp = mat_mul(temp, temp);
        p /= 2;
    }
    return re;
}