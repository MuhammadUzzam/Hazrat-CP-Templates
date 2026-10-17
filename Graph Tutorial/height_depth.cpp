#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES\n"
#define no cout << "NO\n"

const int N = 1e5+10;
vector<int> gp[N];
vector<int> height(N, 0);
vector<int> depth(N, 0);

void dfs(int vertex, int par = 0){

    for(auto child: gp[vertex]){
        if(child == par) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child]+1);
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
    cout << "height, depth" << endl;
    for(int i=1 ; i<=n ; ++i){
        cout << height[i] << ", " << depth[i] << endl;
    }
    return 0;
}