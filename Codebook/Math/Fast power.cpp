ll fast_power(ll b, ll p){
    ll re = 1, sqr = b;
    while(p > 0){
        if(p&1) re = (ll)((__int128)re*sqr%mod);
        sqr = (ll)((__int128)sqr*sqr%mod);
        p /= 2;
    }
    return re;
}