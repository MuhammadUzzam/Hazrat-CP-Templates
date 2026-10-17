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
    int curr;
    node(){
        curr=0;
    }
    node(int curr){
        this->curr=curr;
    }
};
class SegmentTree{
    public:
        vector<int>arr;
        vector<node>tree;
        int n;
        void build(int idx,int l,int r){
            if(l==r){
                tree[idx].curr=arr[l];
                return;
            }
            int mid=l+(r-l)/2;
            build(2*idx+1,l,mid);
            build(2*idx+2,mid+1,r);
            tree[idx]=merge(tree[2*idx+1],tree[2*idx+2]);
        }
        node merge(node a,node b){
            return node(a.curr+b.curr);
        }
        node query(int idx,int l,int r,int lq,int rq){
            if(rq<l||lq>r)  return node();
            if(lq<=l&&rq>=r)    return tree[idx];
            int mid=l+(r-l)/2;
            node res=merge(query(2*idx+1,l,mid,lq,rq),query(2*idx+2,mid+1,r,lq,rq));
            return res;
        }
        void update(int idx,int l,int r,int p,int v){
            if(l==r){
                arr[l]+=v;
                tree[idx].curr+=v;
                return;
            }
            int mid=l+(r-l)/2;
            if(p<=mid)  update(2*idx+1,l,mid,p,v);
            else update(2*idx+2,mid+1,r,p,v);
            tree[idx]=merge(tree[2*idx+1],tree[2*idx+2]);
        }
        SegmentTree(vector<int>&vec){
            arr=vec;
            n=arr.size();
            tree.resize(4*n);
            build(0,0,n-1);
        }
        node getSum(int l,int r){
            return query(0,0,n-1,l,r);
        }
        void setValue(int p,int v){
            update(0,0,n-1,p,v);
        }
};
// I am a loser
void solve(){
    int n,q;cin>>n>>q;
    vi a(n);
    set<int>st;
    for(int i=0;i<n;++i){
        cin>>a[i];
        st.insert(a[i]);
    }
    vector<array<int,3>>opr(q);
    for(int i=0;i<q;++i){
        char x;int y,z;cin>>x>>y>>z;
        opr[i]={x,y,z};
        if(opr[i][0]=='!')  st.insert(opr[i][2]);
        else{
            st.insert(opr[i][1]);
            st.insert(opr[i][2]);
        }
    }  
    vi mp(st.size());
    int i=0;
    for(auto it:st){
        mp[i++]=it;
    }
    vi vec(mp.size(),0);
    SegmentTree seg(vec);
    for(int i=0;i<n;++i){
        seg.setValue(lower_bound(all(mp),a[i])-mp.begin(),1);
    }
    for(int i=0;i<q;++i){
        if(opr[i][0]=='!'){
            auto [k,x]=tuple(opr[i][1],opr[i][2]);
            int curr=lower_bound(all(mp),a[k-1])-mp.begin();
            a[k-1]=x;
            seg.setValue(curr,-1);
            seg.setValue(lower_bound(all(mp),x)-mp.begin(),1);
        }else{
            auto [a,b]=tuple(opr[i][1],opr[i][2]);
            cout<<seg.getSum(lower_bound(all(mp),a)-mp.begin(),lower_bound(all(mp),b)-mp.begin()).curr<<"\n";
        }
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