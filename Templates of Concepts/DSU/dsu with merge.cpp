//Bismillah
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f(i, a, n) for (int i = a; i < n; i++)
#define pr(vec) {for(auto &value: vec) cout<<value<<" ";} nl;
#define iv(vec) for(auto &value: vec) cin>>value;
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uset unordered_set
#define mset unordered_multiset
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pair<int,int>>
#define ld long double
#define nl cout<<"\n";
#define ned ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);int tt = 1;
#define yes cout << "YES\n"
#define no cout << "NO\n"
const int N=2e5+10;

int parent[N];
vector<int>sz(N);
multiset<int>res;
void make(int v){
    parent[v]=v;
    sz[v]=1;
    res.insert(1);
}
int find(int v){
    if(v==parent[v])    return v;
    // Path Compression
    return parent[v]=find(parent[v]);
}
void merge(int a,int b){
    res.erase(res.find(sz[a]));
    res.erase(res.find(sz[b]));
    res.insert(sz[a]+sz[b]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        // Union by size
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;  
        merge(a,b); 
        sz[a]+=sz[b];
    }
}

void solve(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;++i){
        make(i);
    }
    while(q--){
        int a,b;cin>>a>>b;
        Union(a,b);
        if(res.size()==1){
            cout<<0<<endl;
        }else{
            cout<<(*prev(res.end())-*res.begin())<<endl;
        }
    }

    
}

signed main(){
    ned;
    // cin>>tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}