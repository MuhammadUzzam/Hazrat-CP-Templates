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

int n, m;
const int N = 1e3 + 10;
int val[N][N];
int vis[N][N];
int lev[N][N];

vector<pair<int, int>> moverments = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, 
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};
bool isValid(int x, int y){
    return x>=0 && y>=0 && x<n && y<m;
}

int bfs(int source){
    queue<pair<int, int>> q;
    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<n ; ++j){
            if(source == val[i][j]){
                q.push({i, j});
                lev[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    int ans = 0;
    while(!q.empty()){
        auto v = q.front();
        auto v_x = v.first;
        auto v_y = v.second;
        q.pop();
        for(auto move: moverments){
            int childX = v_x + move.first;
            int childY = v_y + move.second;
            if(!isValid(childX, childY))    continue;
            if(vis[childX][childY]) continue;
            q.push({childX, childY});
            lev[childX][childY] = lev[v_x][v_y] + 1;
            vis[childX][childY] = 1;
            ans = max(ans, lev[childX][childY]);

        }
    }
    return ans;


}

void reset(){
    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<m ; ++j){
            vis[i][j] = 0;
            lev[i][j] = 0;
        }
    }
}

int32_t main (){
    fast;
    int t;
    cin >> t;
    while(t--){
        reset();
        cin >> n >> m;
        int mx_val = 0;
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                cin >> val[i][j];
                if(val[i][j] > mx_val){
                    mx_val = val[i][j];
                }
            }
        }
        cout << bfs(mx_val) << endl;
    }
    
    return 0;
}