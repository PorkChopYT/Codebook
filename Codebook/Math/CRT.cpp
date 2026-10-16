// Assume that the modulo are coprime for every pair
// Assume that the product of modulo does not exceed LLONG_MAX

void Exgcd(ll a, ll b, ll &x, ll &y){
    if(!b) x = 1, y = 0;
    else Exgcd(b, a%b, y, x), y -= a/b*x;
}

ll mod_inv(ll a, ll b){ // ax mod b = 1
    ll x = 0, y = 0;
    Exgcd(a, b, x, y);
    return (x%b+b)%b;
}

ll CRT(vector<pair<ll, ll>> eqa){ // {mod, remainder}
    ll pro = 1, ans = 0;
    for(auto [m, r]:eqa) pro *= m;
    for(auto [m, r]:eqa){
        __int128 tmp_pro = ((__int128)(pro/m)*mod_inv(pro/m, m))%pro;
        tmp_pro = (tmp_pro*r)%pro;
        ans = (ans+tmp_pro)%pro;
    }
    return (ans%pro+pro)%pro;
}