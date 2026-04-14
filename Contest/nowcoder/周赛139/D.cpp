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
//const ll mod=1e9+7;
const ll mod=998244353;
const int N=2e5+7;
struct MakeDsu{
    vector<int> fa,sz;
    MakeDsu(int size): fa(size+1),sz(size+1){
        iota(all(fa),0);
    }
    public:
        int findfa(int x);
        void unite(int x,int y);
};
int MakeDsu::findfa(int x){
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
void MakeDsu::unite(int x,int y){
    int a=findfa(x),b=findfa(y);
    if(a==b) return;
    if(sz[b]>sz[a]) swap(a,b);
    fa[b]=a;
    sz[a]+=sz[b];
}
int qpow(int x,int y){
    if(y==0) return 1;
    int res=qpow(x,y/2);
    if(y&1) return res*res%mod*x%mod;
    else return res*res%mod;
}
void Srend(){
    int n,k;cin>>n>>k;
    MakeDsu dsu(n);
    while(k--){
        int u,v;cin>>u>>v;
        dsu.unite(u,v);
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(dsu.fa[i]);
    }
    int ans=s.size();
    ans=qpow(26,ans);
    cout<<ans;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}