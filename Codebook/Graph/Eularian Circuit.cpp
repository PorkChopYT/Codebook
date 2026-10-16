// check if there is multiple edge; if yes, use id for each edge
// the function returns empty vector if no answer exist
// Eulerian Circuit: Exists iff every vertex has an even degree.
// Eulerian Path (not a circuit): Exists iff exactly two vertices have an odd degree
// The vertices with odd degree are start and end points.
// Note that the space complexity is O(m)

ll n, m;
vector<vector<pair<ll, ll>>> v(200010);

struct Eularian_circuit{
    vector<ll> deg, ptr;
    vector<bool> used;
    
    Eularian_circuit(){
        deg.resize(n+10, 0);
        used.resize(m+10, 0);
        ptr.resize(n+10, 0);
        for(ll i = 1; i <= n; i++) deg[i] = v[i].size();
    }
    
    void dfs(ll id, vector<ll> &ans){
        for(; ptr[id] < (ll)v[id].size(); ptr[id]++){
            auto [x, num] = v[id][ptr[id]];
            if(used[num]) continue;
            used[num] = 1;
            dfs(x, ans);
        }
        ans.pb(id);
    }
    
    vector<ll> hierholzer(){
        vector<ll> ans;
        for(ll i = 1; i <= n; i++) if(deg[i]%2 != 0) return {};
        dfs(1, ans); // start with id = 1
        reverse(ans.begin(), ans.end());
        if((ll)ans.size() != m+1) return {};
        return ans;
    }
};