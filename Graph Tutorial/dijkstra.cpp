#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define rep(i,a,b) for(int i=a; i<b; i++)
#define per(i,a,b) for(int i=b-1; i>=a; i--)
#define yes cout << "YES\n"
#define no cout << "NO\n"


const int INF = INT_MAX;
const int N = 1e3 + 10;    
int dijkstra(int source, int n, vector<pair<int, int>> g[]){
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);
    set<pair<int, int>> st;
    dist[source] = 0;
    st.insert({0, source});
    while(!st.empty()){
        auto v = *st.begin();
        int dist_v = v.first;
        int node_v = v.second;
        st.erase(st.begin());
        if(vis[node_v] == 1) continue;
        vis[node_v] = 1;
        for(auto it: g[node_v]){
            int node = it.first;
            int wt = it.second;
            if(wt + dist_v < dist[node]){
                dist[node] = wt+dist_v;
                st.insert({dist[node], node});

            }
        }
    }
    for(int i=1 ; i<=n ; ++i){
        if(dist[i] == INF){
            return -1;
        }
    }
    return *max_element(dist.begin()+1, dist.begin()+n+1);
    
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int, int>> g[N];
    for(auto it: times){
        g[it[0]].push_back({it[1], it[2]});
    }        
    return dijkstra(k, n, g);
}

int32_t main (){
    fast;

    vector<vector<int>> times = {{2,1,1}, {2,3,1}, {3,4,1}};
    int n=4, k=2;
    cout << networkDelayTime(times, n, k);
    
    return 0;
}