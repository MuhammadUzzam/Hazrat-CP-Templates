// ya to cout.flush() use kro ya phr "endl" krlo use. 
int query(int lo,int hi){
    cout<<"? "<<hi-lo+1<<" ";
    for(int i=lo;i<=hi;++i){
        cout<<i+1<<" \n"[i==hi];
    }
    cout.flush();
    int res;cin>>res;
    return res;
}
// I am a loser
void solve(){
    int n;cin>>n;
    vi a(n);iv(a);
    vi pa(n+1);
    for(int i=1;i<=n;++i){
        pa[i]=pa[i-1]+a[i-1];
    }
    int lo=0,hi=n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(lo==hi){
            cout<<"! "<<lo+1<<"\n";cout.flush();return;
        }
        if(query(lo,mid)==pa[mid+1]-pa[lo]){
            lo=mid+1;
        }else{
            hi=mid;
        }
    }
}

