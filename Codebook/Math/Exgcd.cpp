void Exgcd(ll a, ll b, ll &x, ll &y){
    if(!b) x = 1, y = 0;
    else Exgcd(b, a%b, y, x), y -= a/b*x;
}