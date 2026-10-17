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

const int N = 100;
vector<int> gp[N];
int vis[N][N];
int level[N][N];

int getX(string s){
	return s[0] - 'a';
}
int getY(string s){
	return s[1] - '1';
}

vector<pair<int, int>> positions = {
	{-2, 1},
	{-1, 2},
	{1, 2},
	{2, 1},
	{-2, -1},
	{-1, -2},
	{2, -1},
	{1, -2},
};

bool isValid(int x, int y){
	return x>=0 && x<8 && y>=0 && y<8;
}
int bfs(string source, string dest){
	int sourceX = getX(source);
	int sourceY = getY(source);
	int destX = getX(dest);
	int destY = getY(dest);
	queue<pair<int, int>> q;
	q.push({sourceX, sourceY});
	vis[sourceX][sourceY] = 1;
	while(!q.empty()){
		pair<int, int> v = q.front();
		int x = v.first, y = v.second;
		q.pop();
		for(auto movement: positions){
			int childX = movement.first + x;
			int childY = movement.second + y;
			if(!isValid(childX, childY))	continue;
			if(!vis[childX][childY]){
				q.push({childX, childY});
				level[childX][childY] = level[x][y] + 1;
				vis[childX][childY] = 1;
			}
		} 
	}

	return level[destX][destY];
}


int32_t main (){
    fast;
    int t;
    cin >> t;
    while(t--){
    	memset(vis, 0, sizeof(vis));
		memset(level, 0, sizeof(level));
    	string s1, s2;
    	cin >> s1 >> s2;
    	cout << bfs(s1, s2) << endl;
    }
    return 0;
}