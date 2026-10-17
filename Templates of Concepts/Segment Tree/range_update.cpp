#include <bits/stdc++.h>
using namespace std;
#define int long long
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
        int query(int idx,int l,int r,int lq,int rq){
            int curr=0;
            if(rq<l||lq>r)  return curr;
            curr+=tree[idx].curr;
            if(l==r){
                return curr;
            }
            int mid=l+(r-l)/2;
            curr+=query(2*idx+1,l,mid,lq,rq);
            curr+=query(2*idx+2,mid+1,r,lq,rq);
            return curr;
        }
        void update(int idx,int l,int r,int lq,int rq,int v){
            if(rq<l||lq>r)  return;
            if(lq<=l&&rq>=r){
                tree[idx].curr+=v;
                return;
            }
            int mid=l+(r-l)/2;
            update(2*idx+1,l,mid,lq,rq,v);
            update(2*idx+2,mid+1,r,lq,rq,v);
        }
        SegmentTree(vector<int>&vec){
            arr=vec;
            n=arr.size();
            tree.resize(4*n);
            build(0,0,n-1);
        }
        int getSum(int l,int r){
            return query(0,0,n-1,l,r);
        }
        void setValue(int l,int r,int v){
            update(0,0,n-1,l,r,v);
        }
};

// I am a loser
void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n,0);
    SegmentTree seg(a);
    while(m--){
        int t;cin>>t;
        if(t==1){
            int l,r,v;cin>>l>>r>>v;
            seg.setValue(l,r-1,v);
        }else{
            int v;cin>>v;
            cout<<seg.getSum(v,v)<<"\n";
        }
    }

}

signed main(){
    int tt=1;
    // cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}