#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define rep(i,a,b) for(int i=a; i<b; i++)
#define per(i,a,b) for(int i=b-1; i>=a; i--)
#define yes cout << "YES\n"
#define no cout << "NO\n"

const int N = 1e5+10;
vector<bool> vis(N);
vector<int> g[N];
bool isloop = false;

void dfs(int vertex, int parent){
    vis[vertex] = true;
    for(auto child: g[vertex]){
        if(child == parent) continue;
        if(vis[child]){
            isloop = true;
            return;
        }
        dfs(child, vertex);
    }
}


bool isCycle(int V, vector<vector<int>>& edges) {
    int n = V, e = edges.size();
    for(int i=0 ; i<e ; ++i){
        g[edges[i][0]].push_back(edges[i][1]);
        g[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=0 ; i<n ; ++i){
        if(!vis[i]){
            dfs(i, -1);
            if(isloop)  return true;
        }
    }
    return false;
    // for(int i=0 ; i<n ; i++){
    //     for(int j=0 ; j<g[i].size() ; j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
        
}

int32_t main (){
    fast;
    int t=1;
    // cin>>t;
    int v = 4;
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}};

    while(t--)
        cout << isCycle(v, edges);
    return 0;
}