#include<bits/stdc++.h>
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
        node query(int idx,int l,int r,int lq,int rq){
            if(rq<l||lq>r)  return node();
            if(lq<=l&&rq>=r)    return tree[idx];
            int mid=l+(r-l)/2;
            node res=merge(query(2*idx+1,l,mid,lq,rq),query(2*idx+2,mid+1,r,lq,rq));
            return res;
        }
        void update(int idx,int l,int r,int p,int v){
            if(l==r){
                arr[l]=v;
                tree[idx].curr=v;
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

signed main(){
    int n,q;cin>>n>>q;
    vector<int>a(n);
    for(auto &it:a) cin>>it;
    SegmentTree seg(a);
    while(q--){
        int t;cin>>t;
        if(t==1){
            int i,v;cin>>i>>v;
            seg.setValue(i,v);
        }else{
            int l,r;cin>>l>>r;
            cout<<seg.getSum(l,r).curr<<"\n";
        }
    }

    return 0;
}