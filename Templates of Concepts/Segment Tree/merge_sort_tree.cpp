//Bismillah
/*
The world rewards those who are willing to be bad at something long enough to become
great at it!
*/
/*
We are not here to win. We are here... to make our deaths matter.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define hazrat ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);int tt = 1;
#define int long long int
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vvi vector<vi>
#define iv(vec) for(auto &value: vec) cin>>value;
#define pr(vec) {for(auto value: vec) cout<<value<<" ";} nl;
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pii pair<int,int>
#define vpii vector<pii>
#define ld long double
#define nl cout<<"\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
const int MOD=1e9+7;
const int INF=1e18;

struct node{
    vi curr;
};
class SegmentTree{
    public:
        vector<int>arr;
        vector<node>tree;
        int n;
        void build(int idx,int l,int r){
            if(l==r){
                tree[idx].curr.pb(arr[l]);
                return;
            }
            int mid=l+(r-l)/2;
            build(2*idx+1,l,mid);
            build(2*idx+2,mid+1,r);
            tree[idx]=merge(tree[2*idx+1],tree[2*idx+2]);
        }
        node merge(node a,node b){
            node res;
            int i=0,j=0;
            while(i<a.curr.size()&&j<b.curr.size()){
                if(a.curr[i]<b.curr[j]){
                    res.curr.pb(a.curr[i++]);
                }else{
                    res.curr.pb(b.curr[j++]);
                }
            }
            while(i<a.curr.size()){
                res.curr.pb(a.curr[i++]);
            }
            while(j<b.curr.size()){
                res.curr.pb(b.curr[j++]);
            }
            return res;
        }
        int func(vi&a,int k){
            int res=upper_bound(all(a),k)-a.begin();
            return a.size()-res;
        }
        int query(int idx,int l,int r,int lq,int rq,int k){
            if(rq<l||lq>r)  return 0;
            if(lq<=l&&rq>=r){
                return func(tree[idx].curr,k);
            }
            int mid=l+(r-l)/2;
            int res=query(2*idx+1,l,mid,lq,rq,k)+query(2*idx+2,mid+1,r,lq,rq,k);
            return res;
        }
        SegmentTree(vector<int>&vec){
            arr=vec;
            n=arr.size();
            tree.resize(4*n);
            build(0,0,n-1);
        }
        int get(int l,int r,int k){
            return query(0,0,n-1,l,r,k);
        }
};

// I am a loser
void solve(){
    int n;cin>>n;
    vi a(n);iv(a);
    SegmentTree seg(a);
    int q;cin>>q;
    while(q--){
        int i,j,k;cin>>i>>j>>k;
        i--;j--;
        cout<<seg.get(i,j,k)<<"\n";
    }

}

signed main(){
    hazrat;
    // cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}