// if the graph contains cycle -> tpl.size() != n

vector<vector<ll>> v(max_n);
vector<ll> tpl;
ll in_deg[max_n];

void tpl_sort(){
    for(ll i = 1; i <= n; i++) in_deg[i] = 0;
    for(ll i = 1; i <= n; i++) for(ll x: v[i]) in_deg[x]++;
    queue<ll> q; // priority_queue for smallest lexographic order
    for(int i = 1; i <= n; i++) if(in_deg[i] == 0) q.push(i);
    while(!q.empty()){
        ll id = q.front();
        q.pop();
        if(in_deg[id] == 0) tpl.pb(id);
        for(ll x: v[id]){
            in_deg[x] -= 1;
            if(in_deg[x] == 0) q.push(x);
        }
    }
}