// Bismillah
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>

vvi g, rg, dag;
vi vis, comp;
stack<int> st;

void dfs1(int u){
    vis[u] = 1;
    for(int v : g[u]){
        if(!vis[v])
            dfs1(v);
    }
    st.push(u);
}

void dfs2(int u, int scc){
    vis[u] = 1;
    comp[u] = scc;

    for(int v : rg[u]){
        if(!vis[v])
            dfs2(v, scc);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    g.assign(n + 1, {});
    rg.assign(n + 1, {});

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    // ---------- First DFS ----------
    vis.assign(n + 1, 0);

    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs1(i);

    // ---------- Second DFS ----------
    vis.assign(n + 1, 0);
    comp.assign(n + 1, 0);

    int scc = 0;

    while(!st.empty()){
        int u = st.top();
        st.pop();

        if(!vis[u]){
            ++scc;
            dfs2(u, scc);
        }
    }

    // ---------- Condensation DAG ----------
    dag.assign(scc + 1, {});

    for(int u = 1; u <= n; u++){
        for(int v : g[u]){
            if(comp[u] != comp[v])
                dag[comp[u]].push_back(comp[v]);
        }
    }

    // Remove duplicate edges
    for(int i = 1; i <= scc; i++){
        sort(dag[i].begin(), dag[i].end());
        dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
    }

    // ---------- Output ----------
    cout << "Number of SCC = " << scc << "\n";

    cout << "Component of each node:\n";
    for(int i = 1; i <= n; i++)
        cout << comp[i] << " ";
    cout << "\n";

    return 0;
}