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
    MakeDsu(int size): fa(size+1),sz(size+1,1){iota(all(fa),0);}
    public:
        int findfa(int x);
        void unite(int x,int y);
        bool same(int x,int y);
};
int MakeDsu::findfa(int x){
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
void MakeDsu::unite(int x,int y){
    int a=findfa(x),b=findfa(y);
    if(sz[a]<sz[b]) swap(a,b);
    fa[b]=a;
    sz[a]+=sz[b];
    return;
}
bool MakeDsu::same(int x,int y){
    return findfa(x)==findfa(y);
}
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<int>> b(n+1,vector<int>(n+1,0));
    vector<P> g(n*n+7);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        cin>>b[i][j];
        int pos=(i-1)*n+j;
        g[pos]=make_pair(b[i][j],pos);
    }
    sort(g.begin()+1,g.begin()+n*n+1);
    MakeDsu dsu(n+7);
    int sum=0;
    vector<bool> dd(n+1,false);
    for(int i=1;i<=n*n;i++){
        int val=g[i].fr,pos=g[i].sc;
        int fr=(pos-1)/n+1,sc=(pos-1)%n+1;
        if(fr==sc){
            if(!dd[fr]){
                sum+=(a[fr]-1)*val;
                dd[fr]=true;
            }
        }else{
            if(!dsu.same(fr,sc)){
                if(!dd[fr]&&!dd[sc]){
                    sum+=(a[fr]+a[sc]-1)*val;
                }else if(dd[fr]&&!dd[sc]){
                    sum+=(a[sc])*val;
                }else if(!dd[fr]&&dd[sc]){
                    sum+=(a[fr])*val;
                }else sum+=val;
                dd[fr]=true;dd[sc]=true;
                dsu.unite(fr,sc);
            }
        }
    }
    cout<<sum<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}