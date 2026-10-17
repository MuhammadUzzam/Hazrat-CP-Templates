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
class LazySegmentTree{
    public:
        vector<int>arr;
        vector<node>segTree;
        vector<node>lazy;
        int n;
        void build(int idx,int l,int r){
            if(l==r){
                segTree[idx].curr=arr[l];
                return;
            }
            int mid=l+(r-l)/2;
            build(2*idx+1,l,mid);
            build(2*idx+2,mid+1,r);
            segTree[idx]=merge(segTree[2*idx+1],segTree[2*idx+2]);
        }
        node merge(node a,node b){
            return node(a.curr+b.curr);
        }
        void push(int idx,int l,int r){
            if(lazy[idx].curr!=0){
                segTree[idx].curr+=(r-l+1)*lazy[idx].curr;
                if(l!=r){
                    lazy[2*idx+1].curr+=lazy[idx].curr;
                    lazy[2*idx+2].curr+=lazy[idx].curr;
                }
                lazy[idx].curr=0;
            }
        }
        node query(int idx,int l,int r,int lq,int rq){
            push(idx,l,r);
            if(rq<l||lq>r)  return node();
            if(lq<=l&&rq>=r)    return segTree[idx];
            int mid=l+(r-l)/2;
            node res=merge(query(2*idx+1,l,mid,lq,rq),query(2*idx+2,mid+1,r,lq,rq));
            return res;
        }
        void update(int idx,int l,int r,int lq,int rq,int v){
            push(idx,l,r);
            if(rq<l||lq>r)  return;
            if(lq<=l&&rq>=r){
                lazy[idx].curr+=v;
                push(idx,l,r);
                return;
            }
            int mid=l+(r-l)/2;
            update(2*idx+1,l,mid,lq,rq,v);
            update(2*idx+2,mid+1,r,lq,rq,v);
            segTree[idx]=merge(segTree[2*idx+1],segTree[2*idx+2]);
        }
        LazySegmentTree(vector<int>&vec){
            arr=vec;
            n=arr.size();
            segTree.resize(4*n);
            lazy.resize(4*n);
            build(0,0,n-1);
        }
        node getSum(int l,int r){
            return query(0,0,n-1,l,r);
        }
        void setValue(int l,int r,int v){
            update(0,0,n-1,l,r,v);
        }
};

signed main(){
    int n,q;cin>>n>>q;
    vector<int>a(n);
    for(auto &it:a) cin>>it;
    LazySegmentTree seg(a);
    while(q--){
        int t;cin>>t;
        if(t==1){
            int l,r,v;cin>>l>>r>>v;
            seg.setValue(l,r,v);
        }else{
            int l,r;cin>>l>>r;
            cout<<seg.getSum(l,r).curr<<"\n";
        }
    }

    return 0;
}