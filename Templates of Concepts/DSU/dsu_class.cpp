class DSU{
public:
    vector<int>par,sz;
    DSU(int n){
        par.resize(n+1);
        sz.assign(n+1,1);
        iota(par.begin(),par.end(),1);
    }

    int find(int x){
        return par[x]==x?x:par[x]=find(par[x]);
    }

    void unite(int a,int b){
        a=find(a),b=find(b);
        if(a==b)return;
        if(sz[a]<sz[b])swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
    }

    bool same(int a,int b){
        return find(a)==find(b);
    }

    int size(int x){
        return sz[find(x)];
    }
};