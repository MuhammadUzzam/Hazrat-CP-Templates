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

int32_t main (){
    fast;
    int n;  cin >> n;
    vector<vector<int>> dist(n+1, vector<int> (n+1));
    for(int i=1 ; i<=n ; ++i){
        for(int j=1 ; j<=n ; ++j){
            cin >> dist[i][j];
        }
    }
    vector<int> x(n);
    for(auto &it: x)    cin >> it;
    reverse(all(x));
    vector<int> ans;
    for(int k=0 ; k<n ; ++k){
        for(int i=1 ; i<=n ; ++i){
            for(int j=1 ; j<=n ; ++j){
                dist[i][j] = min(dist[i][j], dist[i][x[k]] + dist[x[k]][j]);
            }
        }
        int sum = 0;
        for(int i=0 ; i<=k ; ++i){
            for(int j=0 ; j<=k ; ++j){
                sum += dist[x[i]][x[j]];
            }
        }
        ans.push_back(sum);
    }
    reverse(all(ans));
    for(auto it: ans){
        cout << it << ' ';
    }
    return 0;
}