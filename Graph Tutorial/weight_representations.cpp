#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define rep(i,a,b) for(int i=a; i<b; i++)
#define per(i,a,b) for(int i=b-1; i>=a; i--)
#define read(v, n) vector<int> v(n); rep(i,0,n) cin >> v[i]
#define yes cout << "YES\n"
#define no cout << "NO\n"


const int N = 1e3+10; // Maximum vertices in constraints
vector<int> graph1[N][N];

vector<pair<int, int>> graph2[N];
int32_t main(){
    int n, m;
    cin >> n >> m;
    for(int i=0 ; i<m ; ++i){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        
        graph1[v1][v2] = wt;
        graph1[v2][v1] = wt;

        graph2[v1].push_back({v2, wt});
        graph2[v2].push_back({v1, wt});

    }
    // Adjacency Matrix:
    // Space Complexity (N*N)
    // Don't represent graph of N = 1e5 or more (because max space of array
    // is 1e7 which is below 1e5*1e5 or even 1e4*1e4)
    
    // Adjacency List
    // O(N + M) ->N vertices, M edges
    // N = 10 ^ 5 but  edges must be less than 10 ^ 7

    return 0;
}