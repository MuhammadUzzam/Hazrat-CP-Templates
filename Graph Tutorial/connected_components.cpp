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

const int N = 1e5+10;
vector<bool> vis(N);
vector<int> g[N];

void dfs(int vertex){
    vis[vertex] = true;
    for(auto child: g[vertex]){
        if(vis[child])  continue;
        dfs(child);
    }
}

void solve(){
    int n, e;
    cin >> n >> e;
    for(int i=0 ; i<e ; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ct = 0;
    for(int i=1 ; i<=n ; ++i){
        if(vis[i])  continue;
        dfs(i);
        ct++;
    }
    cout << ct << endl;



}


int32_t main (){
    fast;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}