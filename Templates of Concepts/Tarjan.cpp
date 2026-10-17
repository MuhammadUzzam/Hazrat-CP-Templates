#include<bits/stdc++.h>
using namespace std;

struct TarjanSCC{
    int n;
    int timer=0;
    int scc_count=0;
    vector<vector<int>>g;
    vector<vector<int>>dag;
    vector<int>st;
    vector<bool>in_st;
    vector<int>tin; // Entry time
    vector<int>low; // Lowest reachable discovery time
    vector<int>scc_id;
    set<pair<int,int>>edges;
    TarjanSCC(int n,const vector<vector<int>>&g):g(g),n(n),in_st(n+1),tin(n+1,-1),low(n+1,-1),scc_id(n+1){
        st.reserve(n);
        for(int i=1;i<=n;++i){
            if(tin[i]==-1){
                dfs(i);
            }
        }
        build_dag();
    }
    void dfs(int v){
        st.push_back(v);
        in_st[v]=true;
        tin[v]=low[v]=timer++;
        for(auto u:g[v]){
            if(tin[u]==-1){
                dfs(u);
                low[v]=min(low[v],low[u]);
            }else if(in_st[u]){
                low[v]=min(low[v],tin[u]);
            }
        }
        if(low[v]==tin[v]){
            while(true){
                int u=st.back();
                st.pop_back();
                in_st[u]=false;
                scc_id[u]=scc_count;
                if(u==v)    break;
            }
            scc_count++;
        }
    }
    void build_dag(){
        dag.assign(scc_count,{});
        for(int u=1;u<=n;++u){
            for(auto v:g[u]){
                if(scc_id[u]!=scc_id[v]){
                    edges.insert({scc_id[u],scc_id[v]});
                }
            }
        }
        for(auto [u,v]:edges){
            dag[u].push_back(v);
        }
    }
};

int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>g(n+1);
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
    }
    TarjanSCC ts(n,g);
    cout<<ts.scc_count<<"\n";
    for(int i=1;i<=n;++i){
        cout<<ts.scc_id[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<ts.scc_count;++i){
        cout<<i<<": ";
        for(auto v:ts.dag[i]){
            cout<<v<<" ";
        }
        cout<<"\n";
    }
    return 0;
}