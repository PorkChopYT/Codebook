ll n, m, cnt = 1, group = 0;
vector<vector<pll>> v(500010); // Multiple Edges: v[i].pb({j, edge_id})
vector<vector<ll>> bcc(500010);
ll vis_order[500010], low[500010];
stack<ll> st;
bool cut[500010]; // This detect all articulation Point

void dfs(ll id, ll par_eid){
	vis_order[id] = low[id] = cnt;
	cnt++;
	ll child = 0;
	for(auto [x, eid]: v[id]){
		if(par_eid == eid) continue;
        if(!vis_order[x]){
        	child++;
        	st.push(eid);
        	dfs(x, id);
        	low[id] = min(low[x], low[id]);
			if(low[x] >= vis_order[id]){
        		if(par_eid != -1 || child > 1) cut[id] = 1;
				group++;
				ll cur = 0;
				do{
					cur = st.top();
					bcc[group].pb(cur);
					st.pop();
				}while(eid != cur);
			}
        }
        else if(vis_order[x] < vis_order[id]){
            st.push(eid);
            low[id] = min(low[id], vis_order[x]);
        }
    }
}

void tarjan(){
	for(ll i = 0; i <= n; i++)
		vis_order[i] = low[i] = compress[i] = 0;
	for(ll i = 1; i <= n; i++) if(!vis_order[i]) dfs(i, -1);
}
