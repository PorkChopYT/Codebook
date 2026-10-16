ll inv[200010];
ll factorial[200010];
ll fac_inv[200010];

void calculate(){ // use this in main()
    factorial[0] = 1, inv[1] = 1, fac_inv[0] = 1;
    for(ll i = 1; i <= 200000; i++) factorial[i] = (i*factorial[i-1])%mod;
    for(ll i = 2; i <= 200000; i++) inv[i] = ((ll)mod-(mod/i)*inv[mod%i])%mod; // mod must be prime
    for(ll i = 1; i <= 200000; i++) fac_inv[i]=(fac_inv[i-1]*inv[i])%mod;
}

ll binom(ll a,ll b){
    if(a < b) return 0;
    return ((factorial[a]*fac_inv[b])%mod * fac_inv[a-b])%mod;
}
