const int N=5e5+10;
int parent[N];  // ye immediate parent of a node store krega
int sz[N];
int res[N];
void make(int v){
    parent[v]=v;
    sz[v]=1;
}
// ye group ka leader return krega.
int find(int v){
    // ismein complexity amortized nhi hogi but union by size ki wja se log(n) rhe gi so its acceptable.
    /* 
    amortized na rkhne ka reason ye hai k baaz dafa humein parent ko har find ki query mein update
    nhi krna hota.
    */
    while(v!=parent[v]){
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
        res[b]-=res[a];
    }
}
int get(int v){
    int curr=res[v];
    while(v!=parent[v]){
        curr+=res[parent[v]];
        v=parent[v];
    }
    return curr;
}
// Sample
void solve(){
    int n,m;cin>>n>>m;
    // distinct connected components
    for(int i=1;i<=n;++i){
        make(i);
    }
    while(m--){
        string s;cin>>s;
        if(s=="join"){
            int a,b;cin>>a>>b;
            Union(a,b);
        }else if(s=="add"){
            int u,v;cin>>u>>v;
            res[find(u)]+=v;
        }else{
            int u;cin>>u;
            cout<<get(u)<<"\n";
        }
    }

}
/*
is implementation se har add operation mein jo node hogi uske poora group mein relevant addition hojayegi
and get se hum classic difference array technique se wo addition finalized krlein gai.
*/