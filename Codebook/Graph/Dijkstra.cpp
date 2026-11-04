vector<vector<pll>> v(max_n);
ll dis[max_n];
bool isvisited[max_n];

void dijkstra(ll st){
    for(int i = 1; i <= n; i++){
        isvisited[i] = 0;
        dis[i] = llmx;
    }
    priority_queue<pll, pll, greater<pll>> pq; // dis, tar
    pq.push({0, st}); // change starting point if needed 
    while(pq.size()){
        ll tar = pq.top().ss, len = pq.top().ff;
        pq.pop();
        if(!isvisited[tar]){
            dis[tar] = min(dis[tar], len);
            for(auto [x, w]: v[tar]) pq.push({len+w, x});
            isvisited[tar] = 1;    
        }
    }
}
