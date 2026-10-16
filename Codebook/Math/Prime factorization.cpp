ll is_prime[mx];
ll spf[mx];
vector<vector<pair<ll, ll>>> prime_factor(max_n);
 
 
void finding_prime(ll mx){ // use this in main()
    is_prime[0] = is_prime[1] = 0;
    spf[1] = 1;
    for(ll i = 2; i <= mx; i++) is_prime[i] = 1, spf[i] = 0;
    for(ll i = 2; i <= mx; i++){
        if(!is_prime[i]) continue;
        spf[i] = i;
        for(ll j = i*i; j <= mx; j += i){
            is_prime[j] = 0;
            if(spf[j] == 0) spf[j] = i;
        }
    }
}

void factor(ll k){
    ll ori = k;
    while(k > 1){
        ll p = spf[k], cnt = 0;
        while(k%p == 0){
            k /= p;
            cnt++;
        }
        prime_factor[ori].pb({p, cnt});
    }
}
