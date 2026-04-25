#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define db double
#define fr first
#define sc second
#define endl '\n'
#define all(arr) arr.begin(),arr.end()
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const ll mod=1e9+7;
const ll _mod=998244353;
const int N=1e6+7;
struct MakeTree{
    vector<int> p;
    MakeTree(int size): p(size+1,0){}
    public:
        void add(int idx,int val);
        int query(int x);
};
struct node{
    int l,r,id;
    node(int x,int y,int z){
        l=x;r=y;id=z;
    }
    bool operator < (const node& o) const {
        return r<o.r;
    }
};
inline int lowbit(int x){
    return x&(-x);
}
void MakeTree::add(int idx,int val){
    for(;idx<p.size();idx+=lowbit(idx)) p[idx]+=val;
}
int MakeTree::query(int x){
    int sum=0;
    for(;x>=1;x-=lowbit(x)) sum+=p[x];
    return sum;
}
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int m;cin>>m;
    vector<node> v;
    for(int i=1;i<=m;i++){
        int l,r;cin>>l>>r;
        v.emplace_back(node(l,r,i));
    }
    sort(all(v));
    vector<int> pos(N,-1);
    vector<int> ans(m+1);
    MakeTree tr(n);
    int now=0;
    for(node it:v){
        if(now<it.r)for(int i=now+1;i<=it.r;i++){
            if(pos[a[i]]!=-1) tr.add(pos[a[i]],-1);
            tr.add(i,1);
            pos[a[i]]=i;
        }
        now=it.r;
        ans[it.id]=tr.query(it.r)-tr.query(it.l-1);
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}