ll n, m, cnt = 1, group = 0;
vector<vector<ll>> v(100010);
ll vis_order[100010], low[100010], compress[100010];
stack<ll> st;

void dfs(ll id){
	vis_order[id] = low[id] = cnt;
	st.push(id);
	cnt++;
	for(auto x: v[id]){
        if(!vis_order[x]){
        	dfs(x);
        	low[id] = min(low[x], low[id]);
        }
        else if(!compress[x]) low[id] = min(low[id], vis_order[x]); 
	}
	if(vis_order[id] == low[id]){
		ll cur = 0;
		group++;
		do{
			cur = st.top();
			compress[st.top()] = group;
			st.pop();
		}while(id != cur);
	}
}

void tarjan(){
	for(ll i = 1; i <= n; i++) vis_order[i] = low[i] = compress[i] = 0;
	for(ll i = 1; i <= n; i++) if(!vis_order[i]) dfs(i);
}
