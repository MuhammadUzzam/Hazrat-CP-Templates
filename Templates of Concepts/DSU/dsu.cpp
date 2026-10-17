const int N=5e5+10;
int parent[N];  // ye immediate parent of a node store krega
int sz[N];
void make(int v){
    parent[v]=v;
    sz[v]=1;
}
// ye group ka leader return krega.
int find(int v){
    while(v!=parent[v]){
        parent[v]=parent[parent[v]];
        v=parent[v];
    }
    return v;
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        // Union by size
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;   
        sz[a]+=sz[b];
    }
}
// Sample
void solve(){
    int n,m;cin>>n>>m;
    // distinct connected components
    for(int i=1;i<=n;++i){
        make(i);
    }
    while(m--){
        int a,b;cin>>a>>b;
        Union(a,b);
    }
    int cc=0;
    for(int i=1;i<=n;++i){
        if(find(i)==i){
            cc++;
        }
    }
    cout<<cc<<endl;

}