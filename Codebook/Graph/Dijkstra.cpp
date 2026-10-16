vector<vector<pair<ll,ll>>> v(max_n);
ll dis[max_n];
bool isvisited[max_n];

void dijkstra(){
    for(int i = 1; i <= n; i++){
        isvisited[i] = 0;
        dis[i] = llmx;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; // dis, tar
    pq.push({0, 1}); // change starting point if needed 
    while(pq.size()){
        ll tar = pq.top().second, len = pq.top().first;
        pq.pop();
        if(!isvisited[tar]){
            dis[tar] = min(dis[tar], len);
            for(auto [x, w]: v[tar]) pq.push({len+w, x});
            isvisited[tar] = 1;    
        }
    }
}
