// 0-indexed
// Assume that the input is never an empty string

vector<ll> build_lps(string &p){
    vector<ll> lps;
    lps.pb(0);
    int n = p.size();
    for(int pre = 0, suf = 1; suf < n; suf++){
        while(pre > 0 && p[pre] != p[suf]) pre = lps[pre-1]; 
        if(p[pre] == p[suf]) pre++;
        lps.pb(pre);
    }
    return lps;
}
 
ll kmp(string &s, string &p){ // return vector if index is needed
    vector<ll> lps = build_lps(p);
    ll ans = 0;
    ll n = s.size(), m = p.size();
    for(int i = 0, j = 0; i < n; i++){
        while(j > 0 && s[i] != p[j]) j = lps[j-1];
        if(s[i] == p[j]) j++;
        if(j == m){
            j = lps[j-1];
            ans++; // use vector to store index
        }
    }
    return ans;
}