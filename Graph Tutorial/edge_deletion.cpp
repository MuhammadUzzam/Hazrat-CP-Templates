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
vector<int> subtree_sum(N);
vector<int> val = {11, 12};
void dfs(int vertex, int par = -1){
    subtree_sum[vertex] = val[vertex-1];
    for(auto child: gp[vertex]){
        if(child == par)    continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
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
    int maxprod = 1;
    const int M = 1e9+7;
    for(int i=2 ; i<=n ; ++i){
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - part1;
        maxprod = max(maxprod, (part1*part2)%M);
    }
    cout << maxprod << endl;

    return 0;
}