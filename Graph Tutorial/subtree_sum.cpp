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
vector<int> even_ct(N);
void dfs(int vertex, int par=0){

    subtree_sum[vertex] += vertex;
    if(vertex%2 == 0)   even_ct[vertex]++;
    for(auto child: gp[vertex]){
        if(child == par) continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        even_ct[vertex] += even_ct[child];

    }
}

int32_t main (){
    fast;
    int n;
    cin >> n;
    for(int i=0 ; i<n-1 ; ++i){
        int a, b;
        cin >> a >> b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }   
    dfs(1);
    for(int i=1 ; i<=n ; ++i){
        cout << subtree_sum[i] << " " << even_ct[i] << endl;
    }
    return 0;
}