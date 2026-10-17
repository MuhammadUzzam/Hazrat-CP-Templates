#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
const int INF=4e18;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin>>n;
    vvi dist(n,vi(n));
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>dist[i][j];

    vvi dp(1LL<<n,vi(n,INF));
    dp[1][0]=0;

    for(int mask=1;mask<(1LL<<n);++mask){
        if(!(mask&1)) continue;
        for(int last=0;last<n;++last){
            if(!(mask&(1LL<<last))) continue;
            if(dp[mask][last]==INF) continue;
            for(int nxt=0;nxt<n;++nxt){
                if(mask&(1LL<<nxt)) continue;
                dp[mask|(1LL<<nxt)][nxt]=min(
                    dp[mask|(1LL<<nxt)][nxt],
                    dp[mask][last]+dist[last][nxt]
                );
            }
        }
    }

    int ans=INF;
    for(int last=1;last<n;++last)
        ans=min(ans,dp[(1LL<<n)-1][last]+dist[last][0]);

    cout<<ans;
}