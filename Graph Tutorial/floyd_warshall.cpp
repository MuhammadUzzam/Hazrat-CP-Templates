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

// O(n^3)
const int N = 510;
const int INF = INT_MAX;
int dist[N][N];

int32_t main (){
    fast;
    for(int i=0 ; i<N ; ++i){
        for(int j=0 ; j<N ; ++j){
            if(i == j)  dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    int n, m;   cin >> n >> m;
    for(int i=0 ; i<m ; ++i){
        int x, y, wt;   cin >> x >> y >> wt;
        dist[x][y] = wt;    // For directed graph
    }
    for(int k=1 ; k<=n ; ++k){
        for(int i=1 ; i<=n ; ++i){
            for(int j=1 ; j<=n ; ++j){
                if(dist[i][j] != INF && dist[k][j] != INF){     // This if condition for handling negative weights
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for(int i=1 ; i<=n ; ++i){
        for(int j=1 ; j<=n ; ++j){
            if(dist[i][j] != INF){
                cout << dist[i][j] << ' ';
            }else{
                cout << "INF" << ' ';
            }
        }
        cout << endl;
    }



    return 0;
}