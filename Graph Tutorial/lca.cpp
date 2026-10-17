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

vector<int> parent(N);
void dfs(int vertex, int par = -1){
    parent[vertex] = par;
    for(auto child: gp[vertex]){
        if(child == par)    continue;
        dfs(child, vertex);
    }

}

vector<int> path(int node){
    vector<int> ans;
    while(node!=-1){
        ans.push_back(node);
        node = parent[node];
    }
    reverse(all(ans));
    return ans;
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
    vector<int> path_a = path(9);  
    vector<int> path_b = path(11);
    // for(auto it: path_a){
    //     cout << it << " ";
    // }
    // cout << "\n";
    // for(auto it: path_b){
    //     cout << it << " ";
    // }
    // cout << "\n";
    int lca = -1;
    for(int i=0 ; i<min(path_a.size(), path_b.size()) ; ++i){
        if(path_a[i] == path_b[i]){
            lca = path_a[i];
        }else{
            break;
        }
    }
    cout << lca << endl;


    return 0;
}