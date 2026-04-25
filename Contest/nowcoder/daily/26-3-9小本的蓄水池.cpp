#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define db double
#define fr first
#define sc second
#define endl '\n'
#define all(arr) arr.begin(),arr.end()
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=2e5+7;
struct MakeDsu{
    vector<int> fa,sz,val;
    MakeDsu(int size) : fa(size+1),sz(size+1,1){iota(all(fa),0);}
    public:
        void init(vector<int>& a,int n);
        int findfa(int x);
        void unite(int x,int y);
};
void MakeDsu::init(vector<int>& a,int n){
    for(int i=1;i<=n;i++) val[i]=a[i];
}
int MakeDsu::findfa(int x){
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
void MakeDsu::unite(int x,int y){
    x=findfa(x);
    y=findfa(y);
    if(x==y) return;
    if(sz[x]<sz[y]) swap(x,y);
    fa[y]=x;
    sz[x]+=sz[y];
    val[x]+=val[y];
}
void Srend(){
    int n,m;cin>>n>>m;
    vector<int> a(n+1),pre(n+1);
    MakeDsu dsu(n);dsu.init(a,n);
    for(int i=1;i<=n;i++) cin>>a[i];
    while(m--){
        int op;cin>>op;
        if(op==1){
            int l,r;cin>>l>>r;
            for(int i=dsu.findfa(l);i<r;i=dsu.findfa(i))
                dsu.unite(i,i+1);
        }else{
            int x;cin>>x;
            x=dsu.findfa(x);
            double ans=dsu.val[x]/dsu.sz[x];
            printf("%10lf\n",ans);
        }
    }
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}