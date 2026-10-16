struct MR_test{
    ll fast_power(ll b, ll p, ll m){
        ll re = 1, sqr = b;
        while(p > 0){
            if(p&1) re = (ll)((__int128)re*sqr%m);
            sqr = (ll)((__int128)sqr*sqr%m);
            p /= 2;
        }
        return re;
    }
    
    bool prime_test(ll n, ll base) {
        if (n == base) return true;
        if (n%base == 0) return false;
        ll s = 0, d = n-1;
        while ((d & 1) == 0) s++, d >>= 1;
        ll test = fast_power(base, d, n);
        if (test == 1 || test == n - 1) return true;
        for (int i = 1; i < s; i++) {
            test = (ll)((__int128)test*test%n);
            if(test == n-1) return true;
            if(test == 1) return false;
        }
        return false;
    }
    
    bool Miller_Rabin(ll n) {
        if(n <= 1) return false;
        if(n == 2 || n == 3) return true;
        if((n & 1) == 0) return false;
        ll base[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        for(ll i = 0; i < 12; i++){
            ll b = base[i];
            if (b >= n) continue;
            if (!prime_test(n, b)) return false;
        }
        return true;
    }
};