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
int n,m;
P f(int n){
    int x=(n-1)%m+1,y=(n-1)/m+1;
    return make_pair(x,y);
}
int df(P n){
    int res=n.fr+(n.sc-1)*m;
    return res;
}
struct node{
    int a,b;
    node():a(1),b(1){}
};
struct MakeDsu{
    vector<int> fa,sz;
    vector<node> g;
    MakeDsu(int size): fa(size+1),sz(size+1,1),g(size+1,node()){
        iota(all(fa),0);
    }
    public:
        int findfa(int x);
        void unite(int x,int y,int d);
        bool same(int x,int y);
};
int MakeDsu::findfa(int x){
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
void MakeDsu::unite(int x,int y,int d){
    int a=findfa(x),b=findfa(y);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a,b);
    if(d==0&&g[a].a==g[b].a){
        g[a].b+=g[b].b;
    }
    if(d==1&&g[a].b==g[b].b){
        g[a].a+=g[b].a;
    }
    fa[b]=a;
    sz[a]+=sz[b];
}
bool MakeDsu::same(int x,int y){
    return findfa(x)==findfa(y);
}
void Srend(){
    cin>>n>>m;
    vector<vector<bool>> edge(n*m+7,vector<bool>(n*m+7,true));
    for(int i=1;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            int a=df({j+1,i}),b=df({j+1,i+1});
            edge[a][b]=(s[j]=='0');
            edge[b][a]=(s[j]=='0');

        }   
    }
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=0;j<m-1;j++){
            int a=df({j+1,i}),b=df({j+2,i});
            edge[a][b]=(s[j]=='0');
            edge[b][a]=(s[j]=='0');
        }
    }
    MakeDsu dsu(n*m+7);
    for(int i=1;i<=n*m;i++){
        vector<P> r;
        P p=f(i);
        if(p.fr!=1&&edge[i][i-1]) r.emplace_back(make_pair(i-1,1));
        if(p.fr!=m&&edge[i][i+1]) r.emplace_back(make_pair(i+1,1));
        if(p.sc!=1&&edge[i][i-m]) r.emplace_back(make_pair(i-m,0));
        if(p.sc!=n&&edge[i][i+m]) r.emplace_back(make_pair(i+m,0));
        for(P it:r){
            dsu.unite(i,it.fr,it.sc);
        }
    }
    for(int k=0;k<=1;k++){
        int d=1;
        if(k==0) d=-1;
        for(int i=1;i<=n*m;i++){
            if(d==-1&&f(i).fr==1) continue;
            if(d==1&&f(i).fr==m) continue;
            int x=dsu.findfa(i),y=dsu.findfa(i+d);
            if(dsu.g[x].b==dsu.g[y].b) dsu.unite(x,y,1);
        }
    }
    for(int k=0;k<=1;k++){
        int d=m;
        if(k==0) d=-m;
        for(int i=1;i<=n*m;i++){
            if(d==m&&f(i).sc==n) continue;
            if(d==-m&&f(i).sc==1) continue;
            int x=dsu.findfa(i),y=dsu.findfa(i+m);
            if(dsu.g[x].a==dsu.g[x].a) dsu.unite(x,y,0);
        }
    }
    int e=dsu.findfa(2);
    if(dsu.sz[e]==n*m) cout<<"YES\n";
    else cout<<"NO\n";
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}