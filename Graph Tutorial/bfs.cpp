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
int vis[N];
int level[N];

void bfs(int source){
	queue<int> q;
	q.push(source);
	vis[source] = 1;
	while(!q.empty()){
		int curr_v = q.front();
		q.pop();
		for(auto child: gp[curr_v]){
			if(!vis[child]){
				q.push(child);
				vis[child] = 1;
				level[child] = level[curr_v] + 1;
			}
		}
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
    bfs(1);
    for(int i=1 ; i<=n ; ++i){
    	cout << i << ": " << level[i] << endl;
    }
    return 0;
}