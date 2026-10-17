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
vector<int> gp[N];

vector<int> depth(N);

void dfs(int vertex, int par = -1){

    for(auto child: gp[vertex]){
        if(child == par)    continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }

}


int32_t main (){
    fast;
    int n;
    cin >> n;
    for(int i=0 ; i<n-1 ; ++i){
        int v1, v2;
        cin >> v1 >> v2;
        gp[v1].push_back(v2);
        gp[v2].push_back(v1);
    }
    dfs(1);
    int max_depth = -1, mx_node;
    for(int i=1 ; i<=n ; ++i){
        if(max_depth < depth[i]){
            max_depth = depth[i];
            mx_node = i;
        }
    }
    depth.assign(N, 0);
    dfs(mx_node);
    max_depth = -1;

    for(int i=1 ; i<=n ; ++i){
        if(max_depth < depth[i]){
            max_depth = depth[i];
        }
    }
    cout << max_depth << endl;

   
    return 0;
}