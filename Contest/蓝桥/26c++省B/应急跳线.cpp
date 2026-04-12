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
const int N=2e5+7;
struct MakeDsu{
    vector<int> fa,sz;
    MakeDsu(int size): fa(size+1),sz(size+1,1){
        iota(all(fa),0);
    }
    public:
        int findfa(int x);
        void unite(int x,int y);
        bool check(int x,int y);
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
    return;
}
void Srend(){
    int n,m;cin>>n>>m;
    vector<vector<int>> g(n+1,vector<int>());
    MakeDsu dsu(n);
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        dsu.unite(a,b);
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(dsu.fa[i]);
    }
    int cnt=s.size();
    int ans1=cnt-1,ans2=ceil((2*cnt-2.0)/n);
    cout<<ans1<<" "<<ans2;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}