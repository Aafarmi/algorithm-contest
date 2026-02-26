#include <bits/stdc++.h>
using namespace std;
struct segtree{
    int l,r,val=0,lz=0;//l,e代表线段的左右端点，val代表此线段的数值
}tree[4007];
int a[1000];
void build(int i,int l,int r){//递归构建
    tree[i].l=l;tree[i].r=r;
    if(l==r){
        tree[i].val=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(2*i,l,m);
    build(2*i+1,m+1,r);
    tree[i].val=tree[2*i].val+tree[2*i+1].val;
    return;
}
void pushdown(int i){
    if(tree[i].lz!=0){
        tree[2*i].lz+=tree[i].lz;
        tree[2*i+1].lz+=tree[i].lz;
        int m=(tree[i].l+tree[i].r)>>1;
        tree[2*i].val+=tree[i].lz*(m-tree[i].l+1);
        tree[2*i+1].val+=tree[i].lz*(tree[i].r-m);
        tree[i].lz=0;
    }
    return;
}
int search(int i,int s,int t){//避免混淆意义，用s，t分别表示查询区间的左右端点
    if(s<=tree[i].l&&tree[i].r<=t) return tree[i].val;
    pushdown(i);
    int m=(tree[i].l+tree[i].r)>>1;
    int sum=0;
    if(s<=m) sum+=search(2*i,s,t);
    if(t>m) sum+=search(2*i+1,s,t);
    return sum;
}
void add(int i,int s,int t,int k){//修改
    if(s<=tree[i].l&&tree[i].r<=t){
        tree[i].val+=k*(tree[i].r-tree[i].l+1);
        tree[i].lz+=k;
        return;
    }
    pushdown(i);
    int m=(tree[i].l+tree[i].r)>>1;
    if(s<=m) add(2*i,s,t,k);
    if(t>m) add(2*i+1,s,t,k);
    tree[i].val=tree[2*i].val+tree[2*i+1].val;
    return;
}
void solve(){}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
}