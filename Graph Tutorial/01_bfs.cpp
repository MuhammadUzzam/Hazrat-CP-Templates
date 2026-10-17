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

const int N = 1e5+10+10;
vector<pair<int, int>> gp[N];
vector<int> lev(N, 1e9+7);
int n, m;

int bfs(){
	deque<int> q;
	q.push_back(1);
	lev[1] = 0;
	while(!q.empty()){
		int cur_v = q.front();
		q.pop_front();
		for(auto child: gp[cur_v]){
			int child_v = child.first;
			int wt = child.second;
			
		}	
	}


}


int32_t main (){
    fast;
    cin >> n >> m;
    for(int i=0 ; i<m ; ++i){
    	int x, y;
    	cin >> x >> y;
    	gp[x].push_back({y, 0});
    	gp[y].push_back({x, 1});
    }
    cout << bfs() << endl;
    return 0;
}