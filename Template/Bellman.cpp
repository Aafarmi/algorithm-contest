#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define fr first
#define sc second
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int MAXV=1e6+7;
struct edge{
    int from,to,w;
};
vector<edge> g;
int V,E,s;//顶点数，边数，起点数
int d[MAXV];
bool check(){
    for(int i=1;i<=V;i++) d[i]=0;//初始化为0，为了应对负边
    for(int i=1;i<=V;i++){
        for(int j=1;j<=E;j++){
            edge e=g[j];
            if(d[e.to]>d[e.from]+e.w){
                d[e.to]=d[e.from]+e.w;
                if(i==V) return false;
//如果第V次都更新了，就代表有负环，因为正常图最多更新V-1次
            }
        }
    }
    return true;
}
void Bellman(){
    for(int i=1;i<=V;i++) d[i]=INF;
    d[s]=0;
    while(true){
        bool update=false;
        for(int i=1;i<=E;i++){
            edge e=g[i];
            if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.w){
                d[e.to]=d[e.from]+e.w;
                update=true;
            }
        }
        if(!update) break;
    }
}
void solve(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
        a[0]=gcd(a[0],a[i]);
    ll x=a[0]*n;
    cout<<x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) solve();
}
