ll inv[mx_n];

void linear_inv(){
    inv[1] = 1;
    for(int i = 2; i <= n; i++) inv[i] = (ll)p-(p/i)*inv[p%i]%p;
    // works if p is a prime
}
