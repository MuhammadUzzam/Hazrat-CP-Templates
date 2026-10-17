int n;
int dist[20][20];
int visited_all;
int dp[1048576][20];
int tsp(int mask,int pos){
    // Base Case
    if(mask==visited_all){
        return dist[pos][0];
    }
    if(dp[mask][pos]!=-1)   return dp[mask][pos];
    int ans=INT_MAX;
    for(int city=0;city<n;++city){
        if(!((1LL<<city)&mask)){
            int newAns=dist[pos][city]+tsp(mask|(1LL<<city),city);
            ans=min(ans,newAns);
        }
    }
    return dp[mask][pos]=ans;
}

// I am a loser
void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>dist[i][j];
    visited_all=(1LL<<n)-1;
    cout<<tsp(1,0);
}