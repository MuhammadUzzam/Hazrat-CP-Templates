#include<bits/stdc++.h>
using namespace std;
#define int long long
string num;
// dp[pos][tight][started][state]
int dp[20][2][2][170];
// ----------------------------------------------------
// state = modify according to problem
// ----------------------------------------------------
int dfs(int pos, bool tight, bool started, int state){
    // Base Case
    if(pos==num.size()){
        // Check validity here
        return 1;
    }
    if(dp[pos][tight][started][state]!=-1)
        return dp[pos][tight][started][state];
    int ans=0;
    int limit=tight?(num[pos]-'0'):9;
    for(int digit=0;digit<=limit;++digit){
        bool nextTight=tight&&(digit==limit);
        bool nextStarted=started||(digit!=0);
        int nextState=state;
        if(nextStarted){
            // Update state
            // nextState=...
        }
        ans+=dfs(
            pos+1,
            nextTight,
            nextStarted,
            nextState
        );
    }
    return dp[pos][tight][started][state]=ans;
}
int solve(int x){
    if(x<0)
        return 0;
    num=to_string(x);
    memset(dp,-1,sizeof(dp));
    return dfs(0,1,0,0);
}
signed main(){
    int L,R;
    cin>>L>>R;
    cout<<solve(R)-solve(L-1);
}