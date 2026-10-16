bool is_prime[mx];
vector<ll> prime;
 
void finding_prime(ll mx){
    is_prime[0] = is_prime[1] = 0;
    for(ll i = 2; i <= mx; i++) is_prime[i] = 1;
    for(ll i = 2; i <= mx; i++){
        if(!is_prime[i]) continue;
        prime.pb(i);
        for(ll j = i*i; j <= mx; j += i) is_prime[j]=0;
    }
}