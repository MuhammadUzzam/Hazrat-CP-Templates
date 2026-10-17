//Bismillah
/*
Topo Sort + Cycle Detection (DFS)
Works for Directed Graph
If Cycle exists => Not DAG
*/
// Note: If below function returns {} then provided graph is not DAG.
vi topo_sort(int n,vvi &g){
    vi vis(n+1),topo;
    bool ok=false;
    auto dfs=[&](int u,auto&&self)->void{
        for(auto v:g[u]){
            if(vis[v]==0){
                vis[v]=1;
                self(v,self);
            }else if(vis[v]==1){
                ok=true;
                return;
            }
            if(ok) return;
        }
        vis[u]=2;
        topo.pb(u);
    };
    for(int i=1;i<=n;++i){
        if(vis[i]==0){
            vis[i]=1;
            dfs(i,dfs);
            if(ok)
                return {};
        }
    }
    reverse(all(topo));
    return topo;
}