ll n, m, cnt = 1, group = 1;
vector<vector<pll>> v(100010);
ll vis_order[100010], low[100010], compress[100010];
stack<ll> st;

void dfs(ll id, ll p, ll i){
  	vis_order[id] = low[id] = cnt;
  	st.push(id);
  	cnt++;
  	for(auto [x, eid]: v[id]){
    	if(!vis_order[x]) dfs(x, id, eid);
    	if(eid != i) low[id] = min(low[id], low[x]);
  	}
  	if(vis_order[id] == low[id]){
        ll cur = 0;
        do{
            cur = st.top();
            compress[st.top()] = group;
            st.pop();
        } while(id != cur);
        group++;
  	}
}

void tarjan(){
	for(ll i = 1; i <= n; i++) vis_order[i] = low[i] = compress[i] = 0;
	for(ll i = 1; i <= n; i++) if(!vis_order[i]) dfs(i, i, 0);
}
